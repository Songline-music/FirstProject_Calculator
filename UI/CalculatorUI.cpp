#include "UI/CalculatorUI.hpp"
#include "UI/CalculatorUIHelpers.hpp"

#include <QParallelAnimationGroup>

// 初始化
CalculatorUI::CalculatorUI(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    initUiState();
    initWindowChrome();
    connectSignals();
    setupInputProperties();
    setupHeaderEffects();
    setupExitHoverAnimation();
    setupNativeResizeFrame();
    setupModeDrawer();
}

// 初始化函数
void CalculatorUI::initUiState()
{
    ui.InputLine->setText("0");
    ui.HistoryLine->clear();
    windowAnimGroup = new QParallelAnimationGroup(this);
}

void CalculatorUI::initWindowChrome()
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    setWindowTitle("Calculator");
}