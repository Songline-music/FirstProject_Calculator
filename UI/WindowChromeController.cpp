#include "UI/CalculatorUI.hpp"
#include "UI/CalculatorUIHelpers.hpp"

#include <QScreen>
#include <QCursor>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QEasingCurve>
#include <QWindowStateChangeEvent>
#include <QGraphicsOpacityEffect>
#include <QStyle>

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <windowsx.h>

#ifdef ERROR
#undef ERROR
#endif

// 无边框窗口绘制和交互
bool CalculatorUI::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    Q_UNUSED(eventType);
    MSG* msg = static_cast<MSG*>(message);

    if (msg->message == WM_SYSCOMMAND && ((msg->wParam & 0xFFF0) == SC_MINIMIZE))
    {
        if (!(windowState() & Qt::WindowMinimized))
        {
            onMinimumClicked();
        }
        *result = 0;
        return true;
    }

    if (msg->message == WM_NCHITTEST)
    {
        const POINT pt = { GET_X_LPARAM(msg->lParam), GET_Y_LPARAM(msg->lParam) };
        RECT rc;
        GetWindowRect(HWND(winId()), &rc);

        if (!customMaximized)
        {
            const int border = 10;
            const bool left = pt.x >= rc.left && pt.x < rc.left + border;
            const bool right = pt.x < rc.right && pt.x >= rc.right - border;
            const bool top = pt.y >= rc.top && pt.y < rc.top + border;
            const bool bottom = pt.y < rc.bottom && pt.y >= rc.bottom - border;

            if (left && top) { *result = HTTOPLEFT;     return true; }
            if (right && top) { *result = HTTOPRIGHT;    return true; }
            if (left && bottom) { *result = HTBOTTOMLEFT;  return true; }
            if (right && bottom) { *result = HTBOTTOMRIGHT; return true; }
            if (left) { *result = HTLEFT;        return true; }
            if (right) { *result = HTRIGHT;       return true; }
            if (top) { *result = HTTOP;         return true; }
            if (bottom) { *result = HTBOTTOM;      return true; }
        }

        const QPoint globalPt = QCursor::pos();

        const int dragTopGlobalY =
            mapToGlobal(QPoint(0, ui.InputLine ? ui.InputLine->geometry().top() : height())).y();

        auto inBtnGlobal = [&](QAbstractButton* b) -> bool
            {
                if (!b || !b->isVisible()) return false;
                QRect rg(b->mapToGlobal(QPoint(0, 0)), b->size());
                rg = rg.adjusted(-4, -4, 4, 4);
                return rg.contains(globalPt);
            };

        const bool onTopFuncBtn =
            inBtnGlobal(ui.pushButton_StayOnTop) ||
            inBtnGlobal(ui.pushButton_Minimum) ||
            inBtnGlobal(ui.pushButton_Maximum) ||
            inBtnGlobal(ui.pushButton_Exit) ||
            inBtnGlobal(ui.pushButton_Sonpages) ||
            inBtnGlobal(ui.pushButton_Setting) ||
            inBtnGlobal(ui.pushButton_Help) ||
            inBtnGlobal(ui.pushButton_History);

        if (onTopFuncBtn)
        {
            *result = HTCLIENT;
            return true;
        }

        if (globalPt.y() < dragTopGlobalY)
        {
            if (modeDrawerVisible)
            {
                *result = HTCLIENT;
                return true;
            }

            *result = HTCAPTION;
            return true;
        }
    }

    return QWidget::nativeEvent(eventType, message, result);
}

void CalculatorUI::setupNativeResizeFrame()
{
    HWND hwnd = reinterpret_cast<HWND>(winId());
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style |= WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void CalculatorUI::onMinimumClicked() // 最小化
{
    auto* group = new QParallelAnimationGroup(this);

    auto* fade = new QPropertyAnimation(this, "windowOpacity");
    fade->setDuration(160);
    fade->setStartValue(1.0);
    fade->setEndValue(0.0);

    QRect start = geometry();
    QRect end = start;
    end.setY(start.y() + 20); // 轻微下移，避免生硬
    auto* geo = new QPropertyAnimation(this, "geometry");
    geo->setDuration(160);
    geo->setStartValue(start);
    geo->setEndValue(end);
    geo->setEasingCurve(QEasingCurve::OutCubic);

    group->addAnimation(fade);
    group->addAnimation(geo);

    connect(group, &QParallelAnimationGroup::finished, this, [this, group]()
        {
            showMinimized();
            setWindowOpacity(1.0);
            group->deleteLater();
        });

    group->start();
}

void CalculatorUI::onMaximumClicked() // 最大化/恢复
{
    if (!windowAnimGroup || windowAnimGroup->state() == QAbstractAnimation::Running)
    {
        return;
    }

    const QRect start = geometry();
    const bool targetMax = !customMaximized;
    const QRect end = targetMax
        ? screen()->availableGeometry()
        : (normalRect.isValid() ? normalRect : QRect(100, 100, 518, 800));

    if (targetMax)
    {
        normalRect = start;
    }

    windowAnimGroup->clear();

    auto* geoAnim = new QPropertyAnimation(this, "geometry");
    geoAnim->setDuration(300);
    geoAnim->setStartValue(start);
    geoAnim->setEndValue(end);
    geoAnim->setEasingCurve(QEasingCurve::InOutCubic);

    windowAnimGroup->addAnimation(geoAnim);

    connect(windowAnimGroup, &QParallelAnimationGroup::finished, this, [this, targetMax]()
        {
            customMaximized = targetMax;
        }, Qt::SingleShotConnection);

    windowAnimGroup->start();
}

void CalculatorUI::onExitClicked() // 退出
{
    auto* fade = new QPropertyAnimation(this, "windowOpacity", this);
    fade->setDuration(180);
    fade->setStartValue(1.0);
    fade->setEndValue(0.0);
    connect(fade, &QPropertyAnimation::finished, this, [this]() { close(); });
    fade->start(QAbstractAnimation::DeleteWhenStopped);
}

void CalculatorUI::onStayOnTopClicked() // 置顶
{
    stayOnTopEnabled = !stayOnTopEnabled;

    // 用 Win32 直接切换置顶，避免 setWindowFlag + show() 的闪烁
    HWND hwnd = reinterpret_cast<HWND>(winId());
    SetWindowPos(
        hwnd,
        stayOnTopEnabled ? HWND_TOPMOST : HWND_NOTOPMOST,
        0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE
    );

    if (fadeEffects.contains(ui.pushButton_StayOnTop))
    {
        fadeEffects.value(ui.pushButton_StayOnTop)->setOpacity(stayOnTopEnabled ? 1.0 : 0.2);
    }

    updateStayOnTopButtonStyle();
}

// 无边框窗口操作
void CalculatorUI::mouseReleaseEvent(QMouseEvent* event) // 拖动
{
    if (event->button() == Qt::LeftButton)
    {
        isDragging = false;
    }
    QWidget::mouseReleaseEvent(event);
}

// 显示动画
void CalculatorUI::updateStayOnTopButtonStyle() // 置顶按钮样式更新
{
    if (stayOnTopEnabled)
    {
        ui.pushButton_StayOnTop->setStyleSheet(
            "QPushButton#pushButton_StayOnTop{"
            "background-color: rgba(255,255,255,58);"
            "color:#f5f5f5; border:none; padding:4px; border-radius:4px;}"
            "QPushButton#pushButton_StayOnTop:focus{outline:none;}"
        );
    }
    else
    {
        ui.pushButton_StayOnTop->setStyleSheet(
            "QPushButton#pushButton_StayOnTop{"
            "background-color: transparent;"
            "color:#aaaaaa; border:none; padding:4px; border-radius:4px;}"
            "QPushButton#pushButton_StayOnTop:focus{outline:none;}"
        );
    }
}

void CalculatorUI::changeEvent(QEvent* event) // 最小化恢复动画
{
    QWidget::changeEvent(event);

    if (event->type() != QEvent::WindowStateChange)
    {
        return;
    }

    auto* stateEvent = static_cast<QWindowStateChangeEvent*>(event);
    const bool wasMinimized = (stateEvent->oldState() & Qt::WindowMinimized);
    const bool isNowMinimized = (windowState() & Qt::WindowMinimized);

    if (wasMinimized && !isNowMinimized && !suppressRestoreAnimation)
    {
        const QRect endRect = geometry();
        QRect startRect = endRect;
        startRect.translate(0, 18);

        setWindowOpacity(0.0);
        setGeometry(startRect);

        auto* geo = new QPropertyAnimation(this, "geometry", this);
        geo->setDuration(180);
        geo->setStartValue(startRect);
        geo->setEndValue(endRect);
        geo->setEasingCurve(QEasingCurve::OutCubic);

        auto* opa = new QPropertyAnimation(this, "windowOpacity", this);
        opa->setDuration(180);
        opa->setStartValue(0.0);
        opa->setEndValue(1.0);

        auto* group = new QParallelAnimationGroup(this);
        group->addAnimation(geo);
        group->addAnimation(opa);
        group->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void CalculatorUI::showEvent(QShowEvent* event) // 启动动画
{
    QWidget::showEvent(event);

    if (startupAnimPlayed)
    {
        return;
    }
    startupAnimPlayed = true;

    const QRect endRect = geometry();
    QRect startRect = endRect;
    startRect.translate(0, 16);

    setWindowOpacity(0.0);
    setGeometry(startRect);

    auto* geo = new QPropertyAnimation(this, "geometry", this);
    geo->setDuration(220);
    geo->setStartValue(startRect);
    geo->setEndValue(endRect);
    geo->setEasingCurve(QEasingCurve::OutCubic);

    auto* opa = new QPropertyAnimation(this, "windowOpacity", this);
    opa->setDuration(220);
    opa->setStartValue(0.0);
    opa->setEndValue(1.0);
    opa->setEasingCurve(QEasingCurve::OutCubic);

    auto* group = new QParallelAnimationGroup(this);
    group->addAnimation(geo);
    group->addAnimation(opa);
    group->start(QAbstractAnimation::DeleteWhenStopped);
}

void CalculatorUI::enableHeaderFade(QPushButton* btn) // 标题栏按钮淡入效果
{
    auto* eff = new QGraphicsOpacityEffect(btn);
    eff->setOpacity(0.2);
    btn->setGraphicsEffect(eff);
    btn->setAttribute(Qt::WA_Hover, true);

    auto* anim = new QPropertyAnimation(eff, "opacity", btn);
    anim->setDuration(220);

    fadeEffects.insert(btn, eff);
    fadeAnims.insert(btn, anim);
    btn->installEventFilter(this);
}

void CalculatorUI::setupHeaderEffects() // 标题栏按钮效果设置
{
    enableHeaderFade(ui.pushButton_StayOnTop);
    enableHeaderFade(ui.pushButton_Minimum);
    enableHeaderFade(ui.pushButton_Maximum);

    ui.pushButton_StayOnTop->setIcon(TintIcon(ui.pushButton_StayOnTop->icon(), QSize(20, 19), QColor("#ffffff")));
    ui.pushButton_Minimum->setIcon(TintIcon(ui.pushButton_Minimum->icon(), QSize(20, 20), QColor("#ffffff")));
    ui.pushButton_Maximum->setIcon(TintIcon(ui.pushButton_Maximum->icon(), QSize(15, 15), QColor("#ffffff")));
    ui.pushButton_Sonpages->setIcon(TintIcon(ui.pushButton_Sonpages->icon(), QSize(20, 20), QColor("#ffffff")));
    ui.pushButton_Setting->setIcon(TintIcon(ui.pushButton_Setting->icon(), QSize(20, 20), QColor("#ffffff")));
    ui.pushButton_Help->setIcon(TintIcon(ui.pushButton_Help->icon(), QSize(20, 20), QColor("#ffffff")));
    ui.pushButton_History->setIcon(TintIcon(ui.pushButton_History->icon(), QSize(20, 20), QColor("#ffffff")));

    updateStayOnTopButtonStyle();

    ui.pushButton_Exit->setAttribute(Qt::WA_Hover, true);
    ui.pushButton_Exit->installEventFilter(this);
    ui.pushButton_Exit->setProperty("exitHoverAlpha", 0);
    ui.pushButton_Exit->setProperty("exitHoverTarget", 0);

    ui.pushButton_Exit->setText("");
    QIcon closeIcon = QIcon::fromTheme("window-close");
    if (closeIcon.isNull())
    {
        closeIcon = style()->standardIcon(QStyle::SP_TitleBarCloseButton);
    }
    ui.pushButton_Exit->setIcon(TintIcon(closeIcon, QSize(12, 12), QColor("#ffffff")));
    ui.pushButton_Exit->setFixedSize(38, 30);
    ui.pushButton_Exit->setIconSize(QSize(12, 12));

    ui.pushButton_Exit->setStyleSheet(
        "QPushButton#pushButton_Exit{"
        "background:transparent; border:none; border-radius:4px; padding:4px;}"
        "QPushButton#pushButton_Exit:focus{outline:none;}"
    );

    if (auto* host = ui.pushButton_Exit->parentWidget())
    {
        for (auto* w : host->findChildren<QWidget*>("ExitCloseBg"))
        {
            w->deleteLater();
        }

        auto* exitBg = new QWidget(host);
        exitBg->setObjectName("ExitCloseBg");
        exitBg->setGeometry(ui.pushButton_Exit->geometry());
        exitBg->setAttribute(Qt::WA_TransparentForMouseEvents, true);
        exitBg->setStyleSheet("background-color: rgb(232,17,35); border-radius:4px;");
        exitBg->stackUnder(ui.pushButton_Exit);

        auto* exitBgEff = new QGraphicsOpacityEffect(exitBg);
        exitBgEff->setOpacity(0.0);
        exitBg->setGraphicsEffect(exitBgEff);
    }

    ui.Name->setStyleSheet("color:#ffffff;");
}

void CalculatorUI::setupExitHoverAnimation() // 退出按钮悬停动画
{
    if (exitHoverAnim) { exitHoverAnim->deleteLater(); exitHoverAnim = nullptr; }
    exitHoverAnim = new QVariantAnimation(this);
    exitHoverAnim->setDuration(160);
    exitHoverAnim->setEasingCurve(QEasingCurve::OutCubic);
    exitHoverAnim->setStartValue(0);
    exitHoverAnim->setEndValue(0);

    connect(exitHoverAnim, &QVariantAnimation::valueChanged, this, [this](const QVariant& v)
        {
            const int a = v.toInt();
            ui.pushButton_Exit->setProperty("exitHoverAlpha", a);

            if (auto* host = ui.pushButton_Exit->parentWidget())
            {
                if (auto* bg = host->findChild<QWidget*>("ExitCloseBg"))
                {
                    if (auto* eff = qobject_cast<QGraphicsOpacityEffect*>(bg->graphicsEffect()))
                    {
                        eff->setOpacity(static_cast<qreal>(a) / 180.0);
                    }
                }
            }
        });
}
