#include "UI/CalculatorUI.hpp"
#include "UI/CalculatorUIHelpers.hpp"
#include "Output/Menu.hpp"

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QSpinBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QComboBox>
#include <QFormLayout>
#include <QProgressBar>
#include <QLabel>
#include <QMessageBox>
#include <QTimer>
#include <QPainter>
#include <QEasingCurve>
#include <QVariantAnimation>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

// 侧边页面相关

// 弹窗页面开关动画
void CalculatorUI::startDialogOpenAnim(QDialog* dialog, const QSize& endSize)
{
    if (!dialog) return;

    if (dialog->isVisible())
    {
        if (dialog->windowOpacity() < 0.99)
        {
            dialog->setWindowOpacity(1.0);
        }
        dialog->show();
        dialog->raise();
        dialog->activateWindow();
        return;
    }

    const QPoint center = rect().center();
    const QRect endRect(
        mapToGlobal(center - QPoint(endSize.width() / 2, endSize.height() / 2)),
        endSize);

    QRect startRect = endRect;
    startRect.setWidth(static_cast<int>(endRect.width() * 0.92));
    startRect.setHeight(static_cast<int>(endRect.height() * 0.92));
    startRect.moveCenter(endRect.center());

    dialog->setGeometry(startRect);
    dialog->setWindowOpacity(0.0);
    dialog->show();
    dialog->raise();

    auto* geo = new QPropertyAnimation(dialog, "geometry", dialog);
    geo->setDuration(220);
    geo->setStartValue(startRect);
    geo->setEndValue(endRect);
    geo->setEasingCurve(QEasingCurve::OutCubic);

    auto* opa = new QPropertyAnimation(dialog, "windowOpacity", dialog);
    opa->setDuration(220);
    opa->setStartValue(0.0);
    opa->setEndValue(1.0);
    opa->setEasingCurve(QEasingCurve::OutCubic);

    auto* group = new QParallelAnimationGroup(dialog);
    group->addAnimation(geo);
    group->addAnimation(opa);
    group->start(QAbstractAnimation::DeleteWhenStopped);
}

void CalculatorUI::startDialogCloseAnim(QDialog* dialog, bool& closingFlag)
{
    if (!dialog || !dialog->isVisible() || closingFlag)
    {
        return;
    }

    closingFlag = true;

    const QRect startRect = dialog->geometry();
    QRect endRect = startRect;
    endRect.setWidth(static_cast<int>(startRect.width() * 0.94));
    endRect.setHeight(static_cast<int>(startRect.height() * 0.94));
    endRect.moveCenter(startRect.center());
    endRect.translate(0, 8);

    auto* geo = new QPropertyAnimation(dialog, "geometry", dialog);
    geo->setDuration(180);
    geo->setStartValue(startRect);
    geo->setEndValue(endRect);
    geo->setEasingCurve(QEasingCurve::OutCubic);

    auto* opa = new QPropertyAnimation(dialog, "windowOpacity", dialog);
    opa->setDuration(180);
    opa->setStartValue(dialog->windowOpacity());
    opa->setEndValue(0.0);
    opa->setEasingCurve(QEasingCurve::OutCubic);

    auto* group = new QParallelAnimationGroup(dialog);
    group->addAnimation(geo);
    group->addAnimation(opa);

    connect(group, &QParallelAnimationGroup::finished, this, [dialog, startRect, &closingFlag]()
        {
            dialog->hide();
            dialog->setWindowOpacity(1.0);
            dialog->setGeometry(startRect);
            closingFlag = false;
        });

    group->start(QAbstractAnimation::DeleteWhenStopped);
}

// help页面
void CalculatorUI::onHelpClicked()
{
    ensureHelpDialog();
    showHelpDialogAnimated();
}

void CalculatorUI::ensureHelpDialog()
{
    if (helpState.dialog)
    {
        return;
    }

    helpState.dialog = new QDialog(this);
    helpState.dialog->setObjectName("HelpDialog");
    helpState.dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Window);
    helpState.dialog->setModal(false);
    helpState.dialog->setAttribute(Qt::WA_DeleteOnClose, false);
    helpState.dialog->setMinimumSize(560, 380);
    helpState.dialog->resize(760, 560);
    helpState.resizeMargin = 8;
    helpState.dialog->setStyleSheet(
        "QDialog#HelpDialog{background-color:#1f1f1f; border:1px solid #3a3a3a; border-radius:10px;}"
        "QLabel#HelpTitle{color:#e8e8e8; font-size:22px; font-weight:600;}"
        "QPushButton#HelpClose{background:transparent; color:#cfcfcf; border:none; font-size:20px;}"
        "QTextBrowser{background:#242424; color:#dcdcdc; border:none; padding:14px; font-size:18px; line-height:1.5;}"
        "QScrollBar:vertical{background:#2f2f2f; width:14px; margin:2px; border-radius:7px;}"
        "QScrollBar::handle:vertical{background:#d9d9d9; min-height:32px; border-radius:7px;}"
        "QScrollBar::handle:vertical:hover{background:#f2f2f2;}"
        "QScrollBar::handle:vertical:pressed{background:#ffffff;}"
        "QScrollBar::add-line:vertical,QScrollBar::sub-line:vertical{height:0px;}"
    );

    auto* root = new QVBoxLayout(helpState.dialog);
    root->setContentsMargins(10, 10, 10, 10);
    root->setSpacing(8);

    helpState.head = new QWidget(helpState.dialog);
    helpState.head->setObjectName("HelpHead");
    helpState.head->setFixedHeight(34);

    auto* head = new QHBoxLayout(helpState.head);
    head->setContentsMargins(10, 0, 0, 0);

    auto* title = new QLabel("Help", helpState.head);
    title->setObjectName("HelpTitle");

    helpState.closeBtn = new QPushButton(helpState.head);
    helpState.closeBtn->setObjectName("HelpClose");
    helpState.closeBtn->setFixedSize(28, 28);
    helpState.closeBtn->setAttribute(Qt::WA_Hover, true);
    helpState.closeBtn->installEventFilter(this);
    helpState.closeBtn->setProperty("helpCloseHoverAlpha", 0);
    helpState.closeBtn->setProperty("helpCloseHoverTarget", 0);
    helpState.closeBtn->setText("");
    helpState.closeBtn->setStyleSheet(
        "QPushButton#HelpClose{background:transparent; border:none; border-radius:4px; padding:0px;}"
        "QPushButton#HelpClose:focus{outline:none;}"
    );

    head->addWidget(title);
    head->addStretch();
    head->addWidget(helpState.closeBtn);
    root->addWidget(helpState.head);

    helpState.browser = new QTextBrowser(helpState.dialog);
    helpState.browser->setObjectName("HelpContent");
    helpState.browser->setOpenExternalLinks(true);
    helpState.browser->setPlainText(QString::fromStdString(Menu::help));
    ApplyReadableSpacing(helpState.browser);
    root->addWidget(helpState.browser);

    auto* helpCloseBg = new QWidget(helpState.closeBtn);
    helpCloseBg->setObjectName("HelpCloseBg");
    helpCloseBg->setGeometry(helpState.closeBtn->rect());
    helpCloseBg->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    helpCloseBg->setStyleSheet("background-color: rgb(232,17,35); border-radius:4px;");
    helpCloseBg->lower();

    auto* helpCloseBgEff = new QGraphicsOpacityEffect(helpCloseBg);
    helpCloseBgEff->setOpacity(0.0);
    helpCloseBg->setGraphicsEffect(helpCloseBgEff);

    auto* helpCloseGlyph = new QLabel(QString::fromUtf8("×"), helpState.closeBtn);
    helpCloseGlyph->setObjectName("HelpCloseGlyph");
    helpCloseGlyph->setAlignment(Qt::AlignCenter);
    helpCloseGlyph->setGeometry(helpState.closeBtn->rect());
    helpCloseGlyph->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    helpCloseGlyph->setStyleSheet("color:#ffffff; font-size:20px; background:transparent;");
    helpCloseGlyph->raise();

    helpState.closeHoverAnim = new QVariantAnimation(helpState.dialog);
    helpState.closeHoverAnim->setDuration(160);
    helpState.closeHoverAnim->setEasingCurve(QEasingCurve::OutCubic);
    helpState.closeHoverAnim->setStartValue(0);
    helpState.closeHoverAnim->setEndValue(0);
    connect(helpState.closeHoverAnim, &QVariantAnimation::valueChanged, this, [this](const QVariant& v)
        {
            const int a = v.toInt();
            helpState.closeBtn->setProperty("helpCloseHoverAlpha", a);

            if (auto* bg = helpState.closeBtn->findChild<QWidget*>("HelpCloseBg"))
            {
                if (auto* eff = qobject_cast<QGraphicsOpacityEffect*>(bg->graphicsEffect()))
                {
                    eff->setOpacity(static_cast<qreal>(a) / 180.0);
                }
            }

            if (auto* glyph = helpState.closeBtn->findChild<QLabel*>("HelpCloseGlyph"))
            {
                glyph->raise();
            }
        });

    connect(helpState.closeBtn, &QPushButton::clicked, this, &CalculatorUI::closeHelpDialogAnimated);

    helpState.dialog->setMouseTracking(true);
    helpState.head->setMouseTracking(true);
    helpState.browser->setMouseTracking(true);
    helpState.dialog->installEventFilter(this);
    helpState.head->installEventFilter(this);
    helpState.browser->installEventFilter(this);
    title->installEventFilter(this);
}

void CalculatorUI::showHelpDialogAnimated()
{
    ensureHelpDialog();
    startDialogOpenAnim(helpState.dialog, QSize(760, 560));
}

void CalculatorUI::closeHelpDialogAnimated()
{
    startDialogCloseAnim(helpState.dialog, helpState.closingAnim);
}

// history页面
void CalculatorUI::onHistoryClicked()
{
    showHistoryDialogAnimated();
}

void CalculatorUI::onHistoryClearClicked() // history清除
{
    cal.remove_history();
    refreshHistoryDialogContent();
}

void CalculatorUI::refreshHistoryDialogContent()
{
    if (!historyState.browser)
    {
        return;
    }

    const auto& his = cal.get_history();
    if (his.empty())
    {
        historyState.browser->setPlainText("暂无历史记录");
        return;
    }

    QString text;
    for (const auto& item : his)
    {
        text += QString::fromStdString(item) + "\n";
    }
    historyState.browser->setPlainText(text);
    ApplyReadableSpacing(historyState.browser);
}

void CalculatorUI::ensureHistoryDialog()
{
    if (historyState.dialog)
    {
        return;
    }

    historyState.dialog = new QDialog(this);
    historyState.dialog->setObjectName("HistoryDialog");
    historyState.dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Window);
    historyState.dialog->setModal(false);
    historyState.dialog->setAttribute(Qt::WA_DeleteOnClose, false);
    historyState.dialog->setMinimumSize(560, 380);
    historyState.dialog->resize(760, 560);

    historyState.dialog->setStyleSheet(
        "QDialog#HistoryDialog{background-color:#1f1f1f; border:1px solid #3a3a3a; border-radius:10px;}"
        "QLabel#HistoryTitle{color:#e8e8e8; font-size:22px; font-weight:600;}"
        "QPushButton#HistoryClose{background:transparent; color:#cfcfcf; border:none; font-size:20px;}"

        "QPushButton#HistoryClear{background:transparent; border:none; border-radius:6px; padding:0px;}"
        "QPushButton#HistoryClear:hover{background:rgba(255,255,255,0.08);}"
        "QPushButton#HistoryClear:pressed{background:rgba(255,255,255,0.14);}"

        "QTextBrowser{background:#242424; color:#dcdcdc; border:none; padding:14px; font-size:18px; line-height:1.5;}"
        "QScrollBar:vertical{background:#2f2f2f; width:14px; margin:2px; border-radius:7px;}"
        "QScrollBar::handle:vertical{background:#d9d9d9; min-height:32px; border-radius:7px;}"
        "QScrollBar::handle:vertical:hover{background:#f2f2f2;}"
        "QScrollBar::handle:vertical:pressed{background:#ffffff;}"
        "QScrollBar::add-line:vertical,QScrollBar::sub-line:vertical{height:0px;}"
    );

    auto* root = new QVBoxLayout(historyState.dialog);
    root->setContentsMargins(10, 10, 10, 10);
    root->setSpacing(8);

    historyState.head = new QWidget(historyState.dialog);
    historyState.head->setObjectName("HistoryHead");
    historyState.head->setFixedHeight(34);

    auto* head = new QHBoxLayout(historyState.head);
    head->setContentsMargins(10, 0, 0, 0);

    auto* title = new QLabel("History", historyState.head);
    title->setObjectName("HistoryTitle");

    historyState.clearBtn = new QPushButton(historyState.head);
    historyState.clearBtn->setObjectName("HistoryClear");
    QIcon clearIcon = QIcon::fromTheme("edit-delete");
    historyState.clearBtn->setIcon(clearIcon);
    historyState.clearBtn->setIconSize(QSize(18, 18));
    historyState.clearBtn->setFixedSize(34, 30);

    historyState.closeBtn = new QPushButton(historyState.head);
    historyState.closeBtn->setObjectName("HistoryClose");
    historyState.closeBtn->setFixedSize(28, 28);
    historyState.closeBtn->setAttribute(Qt::WA_Hover, true);
    historyState.closeBtn->installEventFilter(this);
    historyState.closeBtn->setProperty("historyCloseHoverAlpha", 0);
    historyState.closeBtn->setProperty("historyCloseHoverTarget", 0);

    historyState.closeBtn->setText("");
    historyState.closeBtn->setStyleSheet(
        "QPushButton#HistoryClose{background:transparent; border:none; border-radius:4px; padding:0px;}"
        "QPushButton#HistoryClose:focus{outline:none;}"
    );

    auto* historyCloseBg = new QWidget(historyState.closeBtn);
    historyCloseBg->setObjectName("HistoryCloseBg");
    historyCloseBg->setGeometry(historyState.closeBtn->rect());
    historyCloseBg->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    historyCloseBg->setStyleSheet("background-color: rgb(232,17,35); border-radius:4px;");
    historyCloseBg->lower();

    auto* historyCloseBgEff = new QGraphicsOpacityEffect(historyCloseBg);
    historyCloseBgEff->setOpacity(0.0);
    historyCloseBg->setGraphicsEffect(historyCloseBgEff);

    auto* historyCloseGlyph = new QLabel(QString::fromUtf8("×"), historyState.closeBtn);
    historyCloseGlyph->setObjectName("HistoryCloseGlyph");
    historyCloseGlyph->setAlignment(Qt::AlignCenter);
    historyCloseGlyph->setGeometry(historyState.closeBtn->rect());
    historyCloseGlyph->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    historyCloseGlyph->setStyleSheet("color:#ffffff; font-size:20px; background:transparent;");
    historyCloseGlyph->raise();

    head->addWidget(title);
    head->addSpacing(12);
    head->addWidget(historyState.clearBtn);
    head->addStretch();
    head->addWidget(historyState.closeBtn);
    root->addWidget(historyState.head);

    historyState.browser = new QTextBrowser(historyState.dialog);
    historyState.browser->setObjectName("HistoryContent");
    historyState.browser->setOpenExternalLinks(false);
    root->addWidget(historyState.browser);

    connect(historyState.clearBtn, &QPushButton::clicked, this, &CalculatorUI::onHistoryClearClicked);
    connect(historyState.closeBtn, &QPushButton::clicked, this, &CalculatorUI::closeHistoryDialogAnimated);

    historyState.closeHoverAnim = new QVariantAnimation(historyState.dialog);
    historyState.closeHoverAnim->setDuration(160);
    historyState.closeHoverAnim->setEasingCurve(QEasingCurve::OutCubic);
    historyState.closeHoverAnim->setStartValue(0);
    historyState.closeHoverAnim->setEndValue(0);

    connect(historyState.closeHoverAnim, &QVariantAnimation::valueChanged, this, [this](const QVariant& v)
        {
            const int a = v.toInt();
            historyState.closeBtn->setProperty("historyCloseHoverAlpha", a);
            if (auto* bg = historyState.closeBtn->findChild<QWidget*>("HistoryCloseBg"))
            {
                if (auto* eff = qobject_cast<QGraphicsOpacityEffect*>(bg->graphicsEffect()))
                {
                    eff->setOpacity(static_cast<qreal>(a) / 180.0);
                }
            }

            if (auto* glyph = historyState.closeBtn->findChild<QLabel*>("HistoryCloseGlyph"))
            {
                glyph->raise();
            }
        });

    historyState.dialog->setMouseTracking(true);
    historyState.head->setMouseTracking(true);
    historyState.browser->setMouseTracking(true);

    historyState.dialog->installEventFilter(this);
    historyState.head->installEventFilter(this);
    historyState.browser->installEventFilter(this);
    title->installEventFilter(this);
}

void CalculatorUI::showHistoryDialogAnimated()
{
    ensureHistoryDialog();
    refreshHistoryDialogContent();
    startDialogOpenAnim(historyState.dialog, QSize(760, 560));
}

void CalculatorUI::closeHistoryDialogAnimated()
{
    startDialogCloseAnim(historyState.dialog, historyState.closingAnim);
}

// Setting页面
void CalculatorUI::updateSettingGameRowsVisibility()
{
    if (!settingState.form) return;

    const bool gameOn = settingState.gameOnCheck && settingState.gameOnCheck->isChecked();
    const bool unlockOutputMode = gameOn && (cal.get_level() >= cal.get_max_level());

    if (settingState.expRow >= 0) settingState.form->setRowVisible(settingState.expRow, gameOn);
    if (settingState.expBarRow >= 0) settingState.form->setRowVisible(settingState.expBarRow, gameOn);
    if (settingState.tipRow >= 0) settingState.form->setRowVisible(settingState.tipRow, gameOn);
    if (settingState.outputModeRow >= 0) settingState.form->setRowVisible(settingState.outputModeRow, unlockOutputMode);

    if (settingState.tipBtn) settingState.tipBtn->setEnabled(gameOn);
    if (settingState.outputModeCombo) settingState.outputModeCombo->setEnabled(unlockOutputMode);
}

void CalculatorUI::ensureSettingDialog()
{
    if (settingState.dialog) return;

    settingState.dialog = new QDialog(this);
    settingState.dialog->setObjectName("SettingDialog");
    settingState.dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Window);
    settingState.dialog->setModal(false);
    settingState.dialog->setAttribute(Qt::WA_DeleteOnClose, false);
    settingState.dialog->setMinimumSize(620, 420);
    settingState.dialog->resize(760, 560);

    settingState.dialog->setStyleSheet(
        "QDialog#SettingDialog{background-color:#1f1f1f; border:1px solid #3a3a3a; border-radius:10px; color:#e8e8e8;}"
        "QLabel{color:#dcdcdc; font-size:18px;}"
        "QLabel#SettingTitle{color:#e8e8e8; font-size:22px; font-weight:700;}"
        "QCheckBox,QRadioButton{color:#dcdcdc; font-size:17px;}"

        "QRadioButton::indicator{width:14px; height:14px; border-radius:7px; border:1px solid #a8a8a8; background:transparent;}"
        "QRadioButton::indicator:unchecked{border:1px solid #8f8f8f; background:transparent;}"
        "QRadioButton::indicator:checked{border:1px solid #dcdcdc; background:#dcdcdc;}"

        "QSpinBox,QComboBox{background:#242424; color:#e8e8e8; border:1px solid #3a3a3a; border-radius:6px; padding:6px 10px; font-size:17px; min-height:34px;}"

        "QComboBox::drop-down{border:none; width:22px;}"
        "QComboBox QAbstractItemView{background:#242424; color:#e8e8e8; border:1px solid #3a3a3a; selection-background-color:#3a3a3a; selection-color:#ffffff; font-size:16px;}"

        "QPushButton{background:transparent; color:#dcdcdc; border:none; border-radius:6px; padding:8px 14px; font-size:17px;}"
        "QPushButton:hover{background:rgba(255,255,255,0.08);}"
        "QPushButton:pressed{background:rgba(255,255,255,0.14);}"
        "QPushButton#SettingCloseTop{padding:0px; min-width:28px; min-height:28px; font-size:20px; color:#dcdcdc;}"
    );

    auto* root = new QVBoxLayout(settingState.dialog);
    root->setContentsMargins(10, 10, 10, 10);
    root->setSpacing(8);

    // 顶部栏
    settingState.head = new QWidget(settingState.dialog);
    settingState.head->setFixedHeight(34);

    auto* headLay = new QHBoxLayout(settingState.head);
    headLay->setContentsMargins(10, 0, 0, 0);

    auto* settingTitle = new QLabel("Setting", settingState.head);
    settingTitle->setObjectName("SettingTitle");

    settingState.closeTopBtn = new QPushButton(settingState.head);
    settingState.closeTopBtn->setObjectName("SettingCloseTop");
    settingState.closeTopBtn->setFixedSize(28, 28);
    settingState.closeTopBtn->setAttribute(Qt::WA_Hover, true);
    settingState.closeTopBtn->installEventFilter(this);
    settingState.closeTopBtn->setProperty("settingCloseHoverAlpha", 0);
    settingState.closeTopBtn->setProperty("settingCloseHoverTarget", 0);

    settingState.closeTopBtn->setText("");
    settingState.closeTopBtn->setStyleSheet(
        "QPushButton#SettingCloseTop{"
        "background:transparent; border:none; border-radius:4px; padding:0px;}"
        "QPushButton#SettingCloseTop:focus{outline:none;}"
    );

    settingState.closeHoverAnim = new QVariantAnimation(settingState.dialog);
    settingState.closeHoverAnim->setDuration(160);
    settingState.closeHoverAnim->setEasingCurve(QEasingCurve::OutCubic);
    settingState.closeHoverAnim->setStartValue(0);
    settingState.closeHoverAnim->setEndValue(0);

    auto* settingCloseBg = new QWidget(settingState.closeTopBtn);
    settingCloseBg->setObjectName("SettingCloseBg");
    settingCloseBg->setGeometry(settingState.closeTopBtn->rect());
    settingCloseBg->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    settingCloseBg->setStyleSheet("background-color: rgb(232,17,35); border-radius:4px;");
    settingCloseBg->lower();

    auto* settingCloseBgEff = new QGraphicsOpacityEffect(settingCloseBg);
    settingCloseBgEff->setOpacity(0.0);
    settingCloseBg->setGraphicsEffect(settingCloseBgEff);

    auto* settingCloseGlyph = new QLabel(QString::fromUtf8("×"), settingState.closeTopBtn);
    settingCloseGlyph->setObjectName("SettingCloseGlyph");
    settingCloseGlyph->setAlignment(Qt::AlignCenter);
    settingCloseGlyph->setGeometry(settingState.closeTopBtn->rect());
    settingCloseGlyph->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    settingCloseGlyph->setStyleSheet("color:#ffffff; font-size:20px; background:transparent;");
    settingCloseGlyph->raise();

    connect(settingState.closeHoverAnim, &QVariantAnimation::valueChanged, this, [this](const QVariant& v)
        {
            const int a = v.toInt();
            settingState.closeTopBtn->setProperty("settingCloseHoverAlpha", a);

            if (auto* bg = settingState.closeTopBtn->findChild<QWidget*>("SettingCloseBg"))
            {
                if (auto* eff = qobject_cast<QGraphicsOpacityEffect*>(bg->graphicsEffect()))
                {
                    eff->setOpacity(static_cast<qreal>(a) / 180.0);
                }
            }
        });

    headLay->addWidget(settingTitle);
    headLay->addStretch();
    headLay->addWidget(settingState.closeTopBtn);
    root->addWidget(settingState.head);

    auto* formWrap = new QWidget(settingState.dialog);
    auto* formRoot = new QVBoxLayout(formWrap);
    formRoot->setContentsMargins(6, 4, 6, 6);
    formRoot->setSpacing(12);

    auto* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    form->setHorizontalSpacing(14);
    form->setVerticalSpacing(12);

    settingState.precisionSpin = new QSpinBox(settingState.dialog);
    settingState.precisionSpin->setRange(0, 10);
    settingState.precisionSpin->setButtonSymbols(QAbstractSpinBox::NoButtons);

    auto* precisionWrap = new QWidget(settingState.dialog);
    auto* precisionLay = new QHBoxLayout(precisionWrap);
    precisionLay->setContentsMargins(0, 0, 0, 0);
    precisionLay->setSpacing(6);

    auto* precisionBtns = new QWidget(precisionWrap);
    auto* precisionBtnsLay = new QHBoxLayout(precisionBtns);
    precisionBtnsLay->setContentsMargins(0, 0, 0, 0);
    precisionBtnsLay->setSpacing(4);

    auto makeWhiteArrowIcon = [](bool right) -> QIcon
        {
            QPixmap pm(12, 12);
            pm.fill(Qt::transparent);

            QPainter p(&pm);
            p.setRenderHint(QPainter::Antialiasing, true);
            p.setPen(Qt::NoPen);
            p.setBrush(QColor("#ffffff"));

            QPolygonF tri;
            if (right)
            {
                tri << QPointF(3.0, 2.0) << QPointF(9.0, 6.0) << QPointF(3.0, 10.0);
            }
            else
            {
                tri << QPointF(9.0, 2.0) << QPointF(3.0, 6.0) << QPointF(9.0, 10.0);
            }
            p.drawPolygon(tri);
            return QIcon(pm);
        };

    auto* precisionLeftBtn = new QPushButton(precisionBtns);
    precisionLeftBtn->setFixedSize(28, 28);
    precisionLeftBtn->setIcon(makeWhiteArrowIcon(false));
    precisionLeftBtn->setIconSize(QSize(12, 12));
    precisionLeftBtn->setStyleSheet(
        "QPushButton{background:#2b2b2b; border:1px solid #3a3a3a; border-radius:6px;}"
        "QPushButton:hover{background:#3a3a3a;}"
        "QPushButton:pressed{background:#4a4a4a;}"
    );

    auto* precisionRightBtn = new QPushButton(precisionBtns);
    precisionRightBtn->setFixedSize(28, 28);
    precisionRightBtn->setIcon(makeWhiteArrowIcon(true));
    precisionRightBtn->setIconSize(QSize(12, 12));
    precisionRightBtn->setStyleSheet(
        "QPushButton{background:#2b2b2b; border:1px solid #3a3a3a; border-radius:6px;}"
        "QPushButton:hover{background:#3a3a3a;}"
        "QPushButton:pressed{background:#4a4a4a;}"
    );

    precisionBtnsLay->addWidget(precisionLeftBtn);
    precisionBtnsLay->addWidget(precisionRightBtn);

    precisionLay->addWidget(settingState.precisionSpin, 1);
    precisionLay->addWidget(precisionBtns, 0, Qt::AlignRight | Qt::AlignVCenter);

    connect(precisionLeftBtn, &QPushButton::clicked, settingState.precisionSpin, &QSpinBox::stepDown);
    connect(precisionRightBtn, &QPushButton::clicked, settingState.precisionSpin, &QSpinBox::stepUp);
    form->addRow("小数位数", precisionWrap);

    auto* modeWrap = new QWidget(settingState.dialog);
    auto* modeLay = new QHBoxLayout(modeWrap);
    modeLay->setContentsMargins(0, 0, 0, 0);
    modeLay->setSpacing(12);
    settingState.degRadio = new QRadioButton("deg", modeWrap);
    settingState.radRadio = new QRadioButton("rad", modeWrap);
    modeLay->addWidget(settingState.degRadio);
    modeLay->addWidget(settingState.radRadio);
    modeLay->addStretch();
    form->addRow("角度模式", modeWrap);

    settingState.gameOnCheck = new QCheckBox("开启游戏模式", settingState.dialog);
    form->addRow("游戏模式", settingState.gameOnCheck);

    settingState.outputModeCombo = new QComboBox(settingState.dialog);
    settingState.outputModeCombo->addItems({ "Normal", "Emoji", "Random" });

    settingState.form = form;

    settingState.exeLabel = new QLabel(settingState.dialog);
    settingState.expRow = form->rowCount();
    form->addRow("当前经验", settingState.exeLabel);

    settingState.exeBar = new QProgressBar(settingState.dialog);
    settingState.exeBar->setTextVisible(true);
    settingState.exeBar->setMinimumHeight(22);
    settingState.exeBar->setStyleSheet(
        "QProgressBar{background:#242424; border:1px solid #3a3a3a; border-radius:6px; color:#e8e8e8; text-align:center;}"
        "QProgressBar::chunk{background:#62a0ea; border-radius:5px;}"
    );
    settingState.expBarRow = form->rowCount();
    form->addRow("经验进度", settingState.exeBar);

    settingState.tipBtn = new QPushButton("Tip", settingState.dialog);
    settingState.tipBtn->setObjectName("SettingTipBtn");
    settingState.tipBtn->setStyleSheet(
        "QPushButton#SettingTipBtn{"
        "background:#2b2b2b; color:#e8e8e8; border:1px solid #5a5a5a; border-radius:6px; padding:6px 12px;}"
        "QPushButton#SettingTipBtn:hover{background:#353535; border-color:#7a7a7a;}"
        "QPushButton#SettingTipBtn:pressed{background:#404040;}"
    );
    settingState.tipRow = form->rowCount();
    form->addRow("提示", settingState.tipBtn);

    settingState.outputModeRow = form->rowCount();
    form->addRow("输出风格", settingState.outputModeCombo);
    connect(settingState.gameOnCheck, &QCheckBox::toggled, this, [this](bool) {
        updateSettingGameRowsVisibility();
        });
    connect(settingState.tipBtn, &QPushButton::clicked, this, &CalculatorUI::onSettingTipClicked);

    refreshSettingGameInfo();
    updateSettingGameRowsVisibility();

    formRoot->addLayout(form);
    formRoot->addStretch();

    auto* btnRow = new QHBoxLayout();
    btnRow->addStretch();
    settingState.applyBtn = new QPushButton("应用", settingState.dialog);
    settingState.closeBtn = new QPushButton("关闭", settingState.dialog);
    btnRow->addWidget(settingState.applyBtn);
    btnRow->addWidget(settingState.closeBtn);
    formRoot->addLayout(btnRow);

    root->addWidget(formWrap);

    connect(settingState.applyBtn, &QPushButton::clicked, this, &CalculatorUI::onSettingApplyClicked);
    connect(settingState.closeBtn, &QPushButton::clicked, this, &CalculatorUI::closeSettingDialogAnimated);
    connect(settingState.closeTopBtn, &QPushButton::clicked, this, &CalculatorUI::closeSettingDialogAnimated);

    settingState.dialog->setMouseTracking(true);
    settingState.head->setMouseTracking(true);

    settingState.dialog->installEventFilter(this);
    settingState.head->installEventFilter(this);
    settingTitle->installEventFilter(this);
    formWrap->installEventFilter(this);
}

void CalculatorUI::showSettingDialogAnimated()
{
    ensureSettingDialog();
    startDialogOpenAnim(settingState.dialog, QSize(760, 560));
}

void CalculatorUI::closeSettingDialogAnimated()
{
    startDialogCloseAnim(settingState.dialog, settingState.closingAnim);
}

void CalculatorUI::refreshSettingGameInfo()
{
    if (!settingState.exeLabel) return;

    const int lv = cal.get_level();
    const int maxLv = cal.get_max_level();

    if (lv >= maxLv)
    {
        settingState.exeLabel->setText(QString("Lv.%1  MAX").arg(lv));

        if (settingState.exeBar)
        {
            settingState.exeBar->setRange(0, 1);
            settingState.exeBar->setValue(1);
            settingState.exeBar->setFormat("MAX");
        }
    }
    else
    {
        const int cur = cal.get_cur_exe();
        const int need = qMax(1, cal.get_cur_exe_threshold());

        settingState.exeLabel->setText(QString("Lv.%1  %2/%3").arg(lv).arg(cur).arg(need));

        if (settingState.exeBar)
        {
            settingState.exeBar->setRange(0, need);
            settingState.exeBar->setValue(qMin(cur, need));
            settingState.exeBar->setFormat(QString("%1/%2").arg(cur).arg(need));
        }
    }
}

void CalculatorUI::onSettingApplyClicked()
{
    if (!settingState.dialog) return;

    settingState.precision = settingState.precisionSpin->value();
    settingState.degMode = settingState.degRadio->isChecked();
    settingState.gameOn = settingState.gameOnCheck->isChecked();
    settingState.outputModeIndex = settingState.outputModeCombo->currentIndex();

    cal.set_precision(settingState.precision);
    if (settingState.degMode) cal.set_deg();
    else cal.set_rad();

    cal.game_mode(settingState.gameOn);
    switch (settingState.outputModeIndex)
    {
    case 1: cal.set_game_mode(ConstValue::CommandID::EMOJI);  break;
    case 2: cal.set_game_mode(ConstValue::CommandID::RANDOM); break;
    default: cal.set_game_mode(ConstValue::CommandID::NORMAL); break;
    }

    refreshSettingGameInfo();

    auto okIcon = QIcon::fromTheme("dialog-ok-apply");
    if (okIcon.isNull()) okIcon = QIcon::fromTheme("emblem-default");
    if (okIcon.isNull()) okIcon = style()->standardIcon(QStyle::SP_DialogApplyButton);

    settingState.applyBtn->setIcon(okIcon);
    settingState.applyBtn->setToolTip("设置已应用");

    QTimer::singleShot(220, this, [this]()
        {
            closeSettingDialogAnimated();
        });
}

void CalculatorUI::onSettingTipClicked()
{
    if (!settingState.gameOnCheck || !settingState.gameOnCheck->isChecked())
    {
        QMessageBox::information(this, "Tip", "请先开启游戏模式");
        return;
    }

    const QString tip = QString::fromStdString(cal.get_tip());

    QMessageBox msg(this);
    msg.setWindowTitle("Tip");
    msg.setText(tip);
    msg.setIcon(QMessageBox::NoIcon);

    QFont f("Cascadia Mono", 20);
    f.setStyleHint(QFont::Monospace);
    msg.setFont(f);

    msg.setStyleSheet(
        "QLabel{min-width:620px; font-size:22px; color:#e8e8e8; background:transparent;}"
        "QPushButton{min-width:110px; min-height:40px; font-size:18px;}"
        "QMessageBox{background:#1f1f1f;}"
    );
    msg.exec();

    refreshSettingGameInfo();
    updateSettingGameRowsVisibility();
}

void CalculatorUI::onSettingClicked()
{
    ensureSettingDialog();

    settingState.precisionSpin->setValue(settingState.precision);
    settingState.degRadio->setChecked(settingState.degMode);
    settingState.radRadio->setChecked(!settingState.degMode);
    settingState.gameOnCheck->setChecked(settingState.gameOn);
    settingState.outputModeCombo->setCurrentIndex(settingState.outputModeIndex);

    // 每次打开时重置反馈状态
    if (settingState.applyBtn)
    {
        settingState.applyBtn->setIcon(QIcon());
        settingState.applyBtn->setToolTip(QString());
    }

    refreshSettingGameInfo();
    updateSettingGameRowsVisibility();

    showSettingDialogAnimated();
}