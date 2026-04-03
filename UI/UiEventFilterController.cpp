#include "UI/CalculatorUI.hpp"
#include "UI/CalculatorUIHelpers.hpp"

#include <QDialog>
#include <QTextBrowser>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QTimer>
#include <QApplication>
#include <QWindow>
#include <QGraphicsOpacityEffect>
#include <QVariantAnimation>
#include <QPropertyAnimation>

bool CalculatorUI::handleFramelessDialogFilter( // 无边框事件过滤逻辑
    QDialog* dialog,
    QWidget* head,
    int resizeMargin,
    bool& closingFlag,
    std::function<void()> closeFn,
    QObject* watched,
    QEvent* event)
{
    if (!dialog) return false;

    if (event->type() == QEvent::MouseMove)
    {
        auto* me = static_cast<QMouseEvent*>(event);
        const QPoint local = (watched == dialog)
            ? me->position().toPoint()
            : dialog->mapFromGlobal(me->globalPosition().toPoint());

        const Qt::Edges edges = HitTestEdges(dialog->rect(), local, resizeMargin);
        dialog->setCursor(CursorFromEdges(edges));
        return false;
    }

    if (event->type() == QEvent::MouseButtonPress)
    {
        auto* me = static_cast<QMouseEvent*>(event);
        if (me->button() == Qt::LeftButton && dialog->windowHandle())
        {
            const QPoint local = (watched == dialog)
                ? me->position().toPoint()
                : dialog->mapFromGlobal(me->globalPosition().toPoint());

            const Qt::Edges edges = HitTestEdges(dialog->rect(), local, resizeMargin);
            if (edges != Qt::Edges{})
            {
                dialog->windowHandle()->startSystemResize(edges);
                return true;
            }

            if (watched == head)
            {
                dialog->windowHandle()->startSystemMove();
                return true;
            }
        }
        return false;
    }

    if (event->type() == QEvent::Close)
    {
        if (!closingFlag)
        {
            auto* ce = static_cast<QCloseEvent*>(event);
            ce->ignore();
            closeFn();
            return true;
        }
        return false;
    }

    if (event->type() == QEvent::Leave)
    {
        dialog->unsetCursor();
        return false;
    }

    return false;
}
bool CalculatorUI::handleFramelessDialogFilter( // 重构
    FramelessPanelState& state,
    std::function<void()> closeFn,
    QObject* watched,
    QEvent* event)
{
    return handleFramelessDialogFilter(
        state.dialog,
        state.head,
        state.resizeMargin,
        state.closingAnim,
        std::move(closeFn),
        watched,
        event);
}

// 侧边界面过滤
bool CalculatorUI::handleDrawerFilter(QObject* watched, QEvent* event) 
{
    if (watched == modeDrawerMask && event->type() == QEvent::MouseButtonPress)
    {
        if (modeDrawerVisible)
        {
            toggleModeDrawer();
            return true;
        }
    }
    if (modeDrawerVisible && event->type() == QEvent::MouseButtonPress)
    {
        auto* me = dynamic_cast<QMouseEvent*>(event);
        if (me && modeDrawer)
        {
            const QPoint globalPos = me->globalPosition().toPoint();

            const bool inDrawer =
                modeDrawer->rect().contains(modeDrawer->mapFromGlobal(globalPos));

            const bool onDrawerToggleBtn =
                ui.pushButton_Sonpages &&
                ui.pushButton_Sonpages->rect().contains(
                    ui.pushButton_Sonpages->mapFromGlobal(globalPos));

            QWidget* hit = QApplication::widgetAt(globalPos);
            const bool onInteractive = IsInteractiveWidgetOrAncestor(hit);

            // 点击空白处关闭
            if (!inDrawer && !onDrawerToggleBtn && !onInteractive)
            {
                toggleModeDrawer();
            }
        }
    }

    return false;
}

// Help过滤
bool CalculatorUI::handleHelpFilter(QObject* watched, QEvent* event)
{
    
    if (helpState.dialog &&
        (watched == helpState.dialog || watched == helpState.head || watched == helpState.browser))
    {
        if (handleFramelessDialogFilter(
            helpState,
            [this]() { closeHelpDialogAnimated(); },
            watched,
            event))
        {
            return true;
        }
    }

    if (watched == helpState.closeBtn &&
        (event->type() == QEvent::Enter || event->type() == QEvent::Leave))
    {
        if (helpState.closeHoverAnim)
        {
            const bool hover = (event->type() == QEvent::Enter);
            const int target = hover ? 180 : 0;

            const int currentTarget = helpState.closeBtn->property("helpCloseHoverTarget").toInt();
            if (currentTarget == target) return true;
            helpState.closeBtn->setProperty("helpCloseHoverTarget", target);

            const int current = helpState.closeBtn->property("helpCloseHoverAlpha").toInt();
            helpState.closeHoverAnim->stop();
            helpState.closeHoverAnim->setStartValue(current);
            helpState.closeHoverAnim->setEndValue(target);
            helpState.closeHoverAnim->start();
        }
        return true;
    }

    return false;
}

// History过滤
bool CalculatorUI::handleHistoryFilter(QObject* watched, QEvent* event)
{
    
    if (historyState.dialog &&
        (watched == historyState.dialog || watched == historyState.head || watched == historyState.browser))
    {
        if (handleFramelessDialogFilter(
            historyState,
            [this]() { closeHistoryDialogAnimated(); },
            watched,
            event))
        {
            return true;
        }
    }

    if (watched == historyState.closeBtn &&
        (event->type() == QEvent::Enter || event->type() == QEvent::Leave))
    {
        if (historyState.closeHoverAnim)
        {
            const bool hover = (event->type() == QEvent::Enter);
            const int target = hover ? 180 : 0;

            const int currentTarget = historyState.closeBtn->property("historyCloseHoverTarget").toInt();
            if (currentTarget == target) return true;
            historyState.closeBtn->setProperty("historyCloseHoverTarget", target);

            const int current = historyState.closeBtn->property("historyCloseHoverAlpha").toInt();
            historyState.closeHoverAnim->stop();
            historyState.closeHoverAnim->setStartValue(current);
            historyState.closeHoverAnim->setEndValue(target);
            historyState.closeHoverAnim->start();
        }
        return true;
    }

    return false;
}

// Setting过滤
bool CalculatorUI::handleSettingFilter(QObject* watched, QEvent* event)
{
    
    if (settingState.dialog &&
        (watched == settingState.dialog || watched == settingState.head))
    {
        if (handleFramelessDialogFilter(
            settingState,
            [this]() { closeSettingDialogAnimated(); },
            watched,
            event))
        {
            return true;
        }
    }

    if (watched == settingState.closeTopBtn &&
        (event->type() == QEvent::Enter ||
            event->type() == QEvent::Leave ||
            event->type() == QEvent::HoverEnter ||
            event->type() == QEvent::HoverLeave))
    {
        if (settingState.closeHoverAnim)
        {
            const bool isEnter =
                (event->type() == QEvent::Enter || event->type() == QEvent::HoverEnter);

            if (isEnter)
            {
                const int target = 180;
                const int currentTarget = settingState.closeTopBtn->property("settingCloseHoverTarget").toInt();
                if (currentTarget != target)
                {
                    settingState.closeTopBtn->setProperty("settingCloseHoverTarget", target);
                    const int current = settingState.closeTopBtn->property("settingCloseHoverAlpha").toInt();
                    settingState.closeHoverAnim->stop();
                    settingState.closeHoverAnim->setStartValue(current);
                    settingState.closeHoverAnim->setEndValue(target);
                    settingState.closeHoverAnim->start();
                }
            }
            else
            {
                QTimer::singleShot(0, this, [this]()
                    {
                        if (!settingState.closeTopBtn) return;
                        if (settingState.closeTopBtn->underMouse()) return;

                        const int target = 0;
                        const int currentTarget = settingState.closeTopBtn->property("settingCloseHoverTarget").toInt();
                        if (currentTarget == target) return;

                        settingState.closeTopBtn->setProperty("settingCloseHoverTarget", target);
                        const int current = settingState.closeTopBtn->property("settingCloseHoverAlpha").toInt();
                        settingState.closeHoverAnim->stop();
                        settingState.closeHoverAnim->setStartValue(current);
                        settingState.closeHoverAnim->setEndValue(target);
                        settingState.closeHoverAnim->start();
                    });
            }
        }
        return true;
    }

    return false;
}

// 主过滤
bool CalculatorUI::handleHeaderFilter(QObject* watched, QEvent* event)
{
    // 头部退出按键
    if (watched == ui.pushButton_Exit &&
        (event->type() == QEvent::Move || event->type() == QEvent::Resize))
    {
        if (auto* host = ui.pushButton_Exit->parentWidget())
        {
            if (auto* bg = host->findChild<QWidget*>("ExitCloseBg"))
            {
                bg->setGeometry(ui.pushButton_Exit->geometry());
                bg->stackUnder(ui.pushButton_Exit);
            }
        }
        return false;
    }
    if (watched == ui.pushButton_Exit &&
        (event->type() == QEvent::Enter || event->type() == QEvent::Leave))
    {
        if (exitHoverAnim)
        {
            const bool hover = (event->type() == QEvent::Enter);
            const int target = hover ? 180 : 0;
            const int currentTarget = ui.pushButton_Exit->property("exitHoverTarget").toInt();
            if (currentTarget == target) return true;
            ui.pushButton_Exit->setProperty("exitHoverTarget", target);

            const int current = ui.pushButton_Exit->property("exitHoverAlpha").toInt();
            exitHoverAnim->stop();
            exitHoverAnim->setStartValue(current);
            exitHoverAnim->setEndValue(target);
            exitHoverAnim->start();
        }
        return true;
    }
    // 其他头部键透明度动画
    if (fadeAnims.contains(watched))
    {
        auto* anim = fadeAnims.value(watched);
        auto* eff = fadeEffects.value(watched);

        if (event->type() == QEvent::Enter)
        {
            anim->stop();
            anim->setStartValue(eff->opacity());
            anim->setEndValue(1.0);
            anim->start();
        }
        else if (event->type() == QEvent::Leave)
        {
            anim->stop();
            anim->setStartValue(eff->opacity());

            const bool keepBright =
                (watched == ui.pushButton_StayOnTop && stayOnTopEnabled);

            anim->setEndValue(keepBright ? 1.0 : 0.2);
            anim->start();
        }
    }

    return false;
}

// 集中过滤器
bool CalculatorUI::eventFilter(QObject* watched, QEvent* event)
{
    if (handleDrawerFilter(watched, event))  return true;
    if (handleHelpFilter(watched, event))    return true;
    if (handleHistoryFilter(watched, event)) return true;
    if (handleSettingFilter(watched, event)) return true;
    if (handleHeaderFilter(watched, event))  return true;

    return QWidget::eventFilter(watched, event);
}