#include "UI/CalculatorUI.hpp"
#include "UI/CalculatorUIHelpers.hpp"

#include <QVBoxLayout>
#include <QApplication>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QEasingCurve>
#include <QMouseEvent>

// 侧边栏相关信号槽连接
void CalculatorUI::onSonpagesClicked()
{
    toggleModeDrawer();
}

void CalculatorUI::onModeStandardClicked()
{
    setKeyLayoutMode(KeyLayoutMode::Standard);
    if (modeDrawerVisible) toggleModeDrawer();
}

void CalculatorUI::onModeScientificClicked()
{
    setKeyLayoutMode(KeyLayoutMode::Scientific);
    if (modeDrawerVisible) toggleModeDrawer();
}

void CalculatorUI::onModeProgrammerClicked()
{
    setKeyLayoutMode(KeyLayoutMode::Programmer);
    if (modeDrawerVisible) toggleModeDrawer();
}

// 侧边导航栏界面
void CalculatorUI::setupModeDrawer()
{
    modeDrawer = new QWidget(ui.calculatorBody);
    modeDrawer->setObjectName("ModeDrawer");
    modeDrawer->setFixedWidth(170);
    modeDrawer->setStyleSheet(
        "QWidget#ModeDrawer{background:#232323; border:1px solid #3a3a3a; border-radius:8px;}"
        "QPushButton{background:transparent; color:#e8e8e8; border:none; padding:10px; text-align:left; font-size:18px; font-weight:600;}"
        "QPushButton:hover{background:rgba(255,255,255,0.08);}"
    );

    auto* lay = new QVBoxLayout(modeDrawer);
    lay->setContentsMargins(8, 8, 8, 8);
    lay->setSpacing(6);

    modeStandardBtn = new QPushButton("标准", modeDrawer);
    modeScientificBtn = new QPushButton("科学", modeDrawer);
    modeProgrammerBtn = new QPushButton("程序员", modeDrawer);

    modeDrawerMask = new QWidget(ui.calculatorBody);
    modeDrawerMask->setObjectName("ModeDrawerMask");
    modeDrawerMask->setStyleSheet("QWidget#ModeDrawerMask{background:rgba(0,0,0,0.01);}");
    modeDrawerMask->hide();
    modeDrawerMask->installEventFilter(this);

    lay->addWidget(modeStandardBtn);
    lay->addWidget(modeScientificBtn);
    lay->addWidget(modeProgrammerBtn);
    lay->addStretch();

    connect(modeStandardBtn, &QPushButton::clicked, this, &CalculatorUI::onModeStandardClicked);
    connect(modeScientificBtn, &QPushButton::clicked, this, &CalculatorUI::onModeScientificClicked);
    connect(modeProgrammerBtn, &QPushButton::clicked, this, &CalculatorUI::onModeProgrammerClicked);

    modeDrawerAnim = new QPropertyAnimation(modeDrawer, "geometry", this);
    modeDrawerAnim->setDuration(180);
    modeDrawerAnim->setEasingCurve(QEasingCurve::OutCubic);

    const int y = ui.InputLine->geometry().bottom() + 6;
    const int h = ui.calculatorBody->height() - y - 8;
    modeDrawer->setGeometry(-modeDrawer->width(), y, modeDrawer->width(), h);
    modeDrawer->hide();
}

void CalculatorUI::toggleModeDrawer()
{
    if (!modeDrawer || !modeDrawerAnim) return;

    const int y = ui.InputLine->geometry().bottom() + 6;
    const int h = ui.calculatorBody->height() - y - 8;

    const bool opening = !modeDrawerVisible;
    QRect from, to;

    if (opening)
    {
        modeDrawerMask->setGeometry(ui.calculatorBody->rect());
        modeDrawerMask->show();
        modeDrawerMask->raise();
        modeDrawer->raise();

        modeDrawer->show();
        from = QRect(-modeDrawer->width(), y, modeDrawer->width(), h);
        to = QRect(8, y, modeDrawer->width(), h);
    }
    else
    {
        from = QRect(modeDrawer->x(), y, modeDrawer->width(), h);
        to = QRect(-modeDrawer->width(), y, modeDrawer->width(), h);
    }

    modeDrawerAnim->stop();
    QObject::disconnect(modeDrawerAnim, &QPropertyAnimation::finished, this, nullptr);

    modeDrawerAnim->setStartValue(from);
    modeDrawerAnim->setEndValue(to);

    connect(modeDrawerAnim, &QPropertyAnimation::finished, this, [this, opening]()
        {
            if (!opening)
            {
                if (modeDrawer) modeDrawer->hide();
                if (modeDrawerMask) modeDrawerMask->hide();
            }
        });

    modeDrawerVisible = opening;
    modeDrawerAnim->start();
}

void CalculatorUI::setKeyLayoutMode(KeyLayoutMode mode)
{
    keyLayoutMode = mode;

    int targetIndex = 0;
    if (mode == KeyLayoutMode::Standard) targetIndex = 0;
    else if (mode == KeyLayoutMode::Scientific) targetIndex = 1;
    else if (mode == KeyLayoutMode::Programmer) targetIndex = 2;

    if (!ui.KeyStack) return;
    const int currentIndex = ui.KeyStack->currentIndex();
    if (currentIndex == targetIndex) return;
    if (keySwitchAnimating) return;

    QWidget* current = ui.KeyStack->currentWidget();
    QWidget* next = ui.KeyStack->widget(targetIndex);
    if (!current || !next)
    {
        ui.KeyStack->setCurrentIndex(targetIndex);
        return;
    }

    keySwitchAnimating = true;

    const QRect area = ui.KeyStack->rect();
    const int dir = (targetIndex > currentIndex) ? 1 : -1;

    auto* curEff = qobject_cast<QGraphicsOpacityEffect*>(current->graphicsEffect());
    if (!curEff)
    {
        curEff = new QGraphicsOpacityEffect(current);
        current->setGraphicsEffect(curEff);
    }
    curEff->setOpacity(1.0);

    auto* nextEff = qobject_cast<QGraphicsOpacityEffect*>(next->graphicsEffect());
    if (!nextEff)
    {
        nextEff = new QGraphicsOpacityEffect(next);
        next->setGraphicsEffect(nextEff);
    }
    nextEff->setOpacity(0.15);

    next->setGeometry(area.translated(dir * area.width(), 0));
    next->show();
    next->raise();

    auto* curMove = new QPropertyAnimation(current, "geometry", ui.KeyStack);
    curMove->setDuration(180);
    curMove->setStartValue(area);
    curMove->setEndValue(area.translated(-dir * area.width(), 0));
    curMove->setEasingCurve(QEasingCurve::OutCubic);

    auto* nextMove = new QPropertyAnimation(next, "geometry", ui.KeyStack);
    nextMove->setDuration(180);
    nextMove->setStartValue(area.translated(dir * area.width(), 0));
    nextMove->setEndValue(area);
    nextMove->setEasingCurve(QEasingCurve::OutCubic);

    auto* curFade = new QPropertyAnimation(curEff, "opacity", ui.KeyStack);
    curFade->setDuration(150);
    curFade->setStartValue(1.0);
    curFade->setEndValue(0.15);

    auto* nextFade = new QPropertyAnimation(nextEff, "opacity", ui.KeyStack);
    nextFade->setDuration(180);
    nextFade->setStartValue(0.15);
    nextFade->setEndValue(1.0);

    auto* group = new QParallelAnimationGroup(ui.KeyStack);
    group->addAnimation(curMove);
    group->addAnimation(nextMove);
    group->addAnimation(curFade);
    group->addAnimation(nextFade);

    connect(group, &QParallelAnimationGroup::finished, this, [this, targetIndex, current, next, area]()
        {
            ui.KeyStack->setCurrentIndex(targetIndex);
            current->setGeometry(area);
            next->setGeometry(area);

            if (auto* e = qobject_cast<QGraphicsOpacityEffect*>(current->graphicsEffect())) e->setOpacity(1.0);
            if (auto* e = qobject_cast<QGraphicsOpacityEffect*>(next->graphicsEffect())) e->setOpacity(1.0);

            keySwitchAnimating = false;
        });

    group->start(QAbstractAnimation::DeleteWhenStopped);
}

void CalculatorUI::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && modeDrawerVisible && modeDrawer)
    {
        const QPoint globalPos = mapToGlobal(event->position().toPoint());

        const bool inDrawer = modeDrawer->rect().contains(modeDrawer->mapFromGlobal(globalPos));
        const bool onDrawerToggleBtn =
            ui.pushButton_Sonpages &&
            ui.pushButton_Sonpages->rect().contains(ui.pushButton_Sonpages->mapFromGlobal(globalPos));

        QWidget* hit = QApplication::widgetAt(globalPos);
        const bool onInteractive = IsInteractiveWidgetOrAncestor(hit);

        if (!inDrawer && !onDrawerToggleBtn && !onInteractive)
        {
            toggleModeDrawer();
        }
    }

    QWidget::mousePressEvent(event);
}