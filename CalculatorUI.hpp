#pragma once

#include "ui_CalculatorUI.h"
#include "Output/Calculator.hpp"

#include <QtWidgets/QWidget>
#include <QHash>
#include <QString>
#include <QPoint>
#include <QRect>
#include <QtCore/qglobal.h>
#include <functional>

class QPushButton;
class QTextBrowser;
class QSpinBox;
class QRadioButton;
class QCheckBox;
class QComboBox;
class QLabel;
class QFormLayout;
class QProgressBar;
class QStackedWidget;
class QMouseEvent;
class QByteArray;
class QPropertyAnimation;
class QGraphicsOpacityEffect;
class QParallelAnimationGroup;
class QVariantAnimation;
class QDialog;
class QObject;
class QEvent;
class QShowEvent;

// 总头实现ui调度
class CalculatorUI : public QWidget
{
    Q_OBJECT
        
public:
    CalculatorUI(QWidget *parent = nullptr);

protected:
    // 重写事件处理
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    bool eventFilter(QObject* watched, QEvent* event) override;
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;
    void changeEvent(QEvent* event) override;
    void showEvent(QShowEvent* event) override;

private slots:
    // 连接信号槽
    void onNumberInputClicked();
    void onOperatorInputClicked();
    void onFunctionInputClicked();
    void onClearAllClicked();
    void onClearCurrentClicked();
    void onEqualInputClicked();
    void onBackSpaceClicked();
    void onMinimumClicked();
    void onMaximumClicked();
    void onExitClicked();
    void onStayOnTopClicked();
    void onHelpClicked();
    void onHistoryClicked();
    void onHistoryClearClicked();
    void onSettingClicked();
    void onSettingApplyClicked();
    void onSettingTipClicked();
    void onSonpagesClicked();
    void onModeStandardClicked();
    void onModeScientificClicked();
    void onScientificTrigBarClicked();
    void onScientificMoreFuncBarClicked();
    void onScientificAngleModeClicked();
    void onModeProgrammerClicked();

private:
    // 无边框基础结构体
    struct FramelessPanelState
    {
        QDialog* dialog = nullptr;
        QWidget* head = nullptr;
        QVariantAnimation* closeHoverAnim = nullptr;
        int resizeMargin = 8;
        bool closingAnim = false;
    };
    struct HelpState : FramelessPanelState // help
    {
        QTextBrowser* browser = nullptr;
        QPushButton* closeBtn = nullptr;
    };
    struct HistoryState : FramelessPanelState // history
    {
        QTextBrowser* browser = nullptr;
        QPushButton* closeBtn = nullptr;
        QPushButton* clearBtn = nullptr;
    };
    struct SettingState : FramelessPanelState // setting
    {
        QSpinBox* precisionSpin = nullptr;
        QRadioButton* degRadio = nullptr;
        QRadioButton* radRadio = nullptr;
        QCheckBox* gameOnCheck = nullptr;
        QComboBox* outputModeCombo = nullptr;
        QPushButton* applyBtn = nullptr;
        QPushButton* closeBtn = nullptr;
        QPushButton* closeTopBtn = nullptr;
        QLabel* exeLabel = nullptr;
        QProgressBar* exeBar = nullptr;
        QPushButton* tipBtn = nullptr;
        QFormLayout* form = nullptr;
        int precision = ConstValue::default_decimal;
        int expRow = -1;
        int tipRow = -1;
        int expBarRow = -1;
        int outputModeRow = -1;
        bool degMode = false;
        bool gameOn = false;
        int outputModeIndex = 0;
    };

    // UI组件
    Ui::CalculatorUIClass ui;
    Calculator cal;

    bool hasResult = false;
    QString lastResult = "0";

    bool isDragging = false;
    QPoint dragOffset;

    QHash<QObject*, QPropertyAnimation*> fadeAnims;
    QHash<QObject*, QGraphicsOpacityEffect*> fadeEffects;

    QParallelAnimationGroup* windowAnimGroup = nullptr;
    QRect normalRect;
    bool customMaximized = false;

    bool suppressRestoreAnimation = false;
    QVariantAnimation* exitHoverAnim = nullptr;

    bool stayOnTopEnabled = false;
    void updateStayOnTopButtonStyle();

    // 初始化和辅助函数
    void initUiState();
    void initWindowChrome();
    void connectSignals();
    void setupInputProperties();
    void setupHeaderEffects();
    void setupExitHoverAnimation();
    void setupNativeResizeFrame();
    void applyDwmShadowForWidget(QWidget* widget, bool enabled = true);
    void applyFunctionToken(const QString& func);
    void applyOperatorToken(const QString& op);
    void enableHeaderFade(QPushButton* btn);
    bool startupAnimPlayed = false;
    bool handleDrawerFilter(QObject*, QEvent*);
    bool handleHelpFilter(QObject*, QEvent*);
    bool handleHistoryFilter(QObject*, QEvent*);
    bool handleSettingFilter(QObject*, QEvent*);
    bool handleHeaderFilter(QObject*, QEvent*);

    // 弹窗开关动画
    void startDialogOpenAnim(QDialog* dialog, const QSize& endSize);
    void startDialogCloseAnim(QDialog* dialog, bool& closingFlag);

    // 无边框模板
    bool handleFramelessDialogFilter(QDialog* dialog, QWidget* head, int resizeMargin, bool& closingFlag, std::function<void()> closeFn, QObject* watched, QEvent* event);
    bool handleFramelessDialogFilter(FramelessPanelState& state, std::function<void()> closeFn, QObject* watched, QEvent* event);

    // Help 面板
    HelpState helpState;
    void ensureHelpDialog();
    void showHelpDialogAnimated();
    void closeHelpDialogAnimated();

    // History 面板
    HistoryState historyState;
    void ensureHistoryDialog();
    void showHistoryDialogAnimated();
    void closeHistoryDialogAnimated();
    void refreshHistoryDialogContent();

    // Setting 面板
    SettingState settingState;
    void ensureSettingDialog();
    void showSettingDialogAnimated();
    void closeSettingDialogAnimated();
    void refreshSettingGameInfo();
    void updateSettingGameRowsVisibility();

    // 侧面导航栏界面
    enum class KeyLayoutMode
    {
        Standard = 0,
        Scientific = 1,
        Programmer = 2
    };
    KeyLayoutMode keyLayoutMode = KeyLayoutMode::Standard;
    QWidget* modeDrawer = nullptr;
    QWidget* modeDrawerMask = nullptr;
    QPushButton* modeStandardBtn = nullptr;
    QPushButton* modeScientificBtn = nullptr;
    QPushButton* modeProgrammerBtn = nullptr;
    QPropertyAnimation* modeDrawerAnim = nullptr;
    bool modeDrawerVisible = false;
    bool keySwitchAnimating = false;
    void setupModeDrawer();
    void toggleModeDrawer();
    void setKeyLayoutMode(KeyLayoutMode mode);

    // 科学头部功能区
    bool scientificDegMode = false;
};