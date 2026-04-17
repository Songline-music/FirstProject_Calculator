#include "UI/CalculatorUI.hpp"
#include "UI/CalculatorUIHelpers.hpp"

#include <QRegularExpression>
#include <QMessageBox>
#include <QLabel>
#include <QStyle>
#include <QStyleOptionFrame>
#include <QMenu>
#include <QWidgetAction>
#include <QGridLayout>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>

// 输入处理相关

// 函数/运算符输入处理
void CalculatorUI::applyFunctionToken(const QString& func)
{
    QString text = ui.InputLine->text();

    if (hasResult)
    {
        text = lastResult.trimmed().isEmpty() ? QStringLiteral("0") : lastResult.trimmed();
        ui.InputLine->setText(text);
        hasResult = false;
    }

    if (ui.InputLine->hasSelectedText())
    {
        const QString sel = ui.InputLine->selectedText();
        ui.InputLine->insert(func + "(" + sel + ")");
        return;
    }

    const int cursorPos = ui.InputLine->cursorPosition();

    if (cursorPos < text.size())
    {
        auto isTokenChar = [](QChar ch) -> bool
            {
                return ch.isLetterOrNumber() || ch == '.' || ch == '_';
            };

        int left = cursorPos - 1;
        int right = cursorPos;

        while (left >= 0 && isTokenChar(text[left])) --left;
        while (right < text.size() && isTokenChar(text[right])) ++right;

        // 光标附近有token
        if (right > left + 1)
        {
            const QString token = text.mid(left + 1, right - left - 1);
            const QString wrapped = func + "(" + token + ")";
            text.replace(left + 1, right - left - 1, wrapped);
            ui.InputLine->setText(text);
            ui.InputLine->setCursorPosition(left + 1 + wrapped.size());
        }
        else
        {
            // 没有token
            const QString insertText = func + "()";
            ui.InputLine->setCursorPosition(cursorPos);
            ui.InputLine->insert(insertText);
            ui.InputLine->setCursorPosition(cursorPos + func.size() + 1);
        }
        return;
    }

    const QString src = text.trimmed();
    if (src.isEmpty())
    {
        const QString out = func + "()";
        ui.InputLine->setText(out);
        ui.InputLine->setCursorPosition(func.size() + 1); // 光标在括号内
        return;
    }

    // 右括号结尾
    if (src.endsWith(')'))
    {
        int depth = 0, left = -1;
        for (int i = src.size() - 1; i >= 0; --i)
        {
            if (src[i] == ')') ++depth;
            else if (src[i] == '(')
            {
                --depth;
                if (depth == 0) { left = i; break; }
            }
        }

        if (left != -1)
        {
            int start = left;
            while (start > 0 && src[start - 1].isLetter()) --start;

            const QString prefix = src.left(start);
            const QString inner = src.mid(start);
            const QString out = prefix + func + "(" + inner + ")";
            ui.InputLine->setText(out);
            ui.InputLine->setCursorPosition(out.size());
            return;
        }
    }

    // 尾token
    static const QRegularExpression tailExpr(
        R"(((?:(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+\-]?\d+)?(?:[A-Za-z_][A-Za-z0-9_]*)?)|(?:[A-Za-z_][A-Za-z0-9_]*))$)");

    QRegularExpressionMatch m = tailExpr.match(src);
    if (m.hasMatch())
    {
        int tokenStart = m.capturedStart(1);
        QString token = m.captured(1);
        QString prefix = src.left(tokenStart);

        // 仅处理一元负号
        if (!prefix.isEmpty() && prefix.back() == '-')
        {
            const int p = prefix.size() - 1;
            const bool unary = (p == 0) || QString("+-*/%^,( ").contains(prefix[p - 1]);
            if (unary)
            {
                prefix.chop(1);
                token.prepend('-');
            }
        }

        const QString out = prefix + func + "(" + token + ")";
        ui.InputLine->setText(out);
        ui.InputLine->setCursorPosition(out.size());
        return;
    }

    // 无token时
    const QString out = src + func + "()";
    ui.InputLine->setText(out);
    ui.InputLine->setCursorPosition(out.size() - 1);
}

void CalculatorUI::applyOperatorToken(const QString& op)
{
    if (hasResult)
    {
        const QString base = lastResult.trimmed().isEmpty() ? QStringLiteral("0") : lastResult.trimmed();
        ui.InputLine->setText(base + op);
        hasResult = false;
        return;
    }

    hasResult = false;
    ui.InputLine->insert(op);
}

void CalculatorUI::onNumberInputClicked() // 数字
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button)
    {
        return;
    }

    const QString buttonText = GetButtonInput(button);
    QString text = ui.InputLine->text();

    auto hasDotInCurrentNumber = [this]() -> bool
        {
            const QString s = ui.InputLine->text();
            const int n = s.size();
            int pos = ui.InputLine->cursorPosition();
            if (pos < 0) pos = 0;
            if (pos > n) pos = n;

            auto isNumChar = [](QChar ch) -> bool
                {
                    return ch.isDigit() || ch == '.';
                };

            int left = pos - 1;
            while (left >= 0 && isNumChar(s[left])) --left;

            int right = pos;
            while (right < n && isNumChar(s[right])) ++right;

            const QString token = s.mid(left + 1, right - left - 1);
            return token.contains('.');
        };

    if (hasResult)
    {
        if (buttonText == ".")
        {
            ui.InputLine->setText("0.");
            ui.InputLine->setCursorPosition(2);
            hasResult = false;
            return;
        }

        ui.InputLine->setText("0");
        hasResult = false;
        text = ui.InputLine->text();
    }

    if (buttonText == ".")
    {
        if (hasDotInCurrentNumber())
        {
            return;
        }
    }
    else if (text == "0")
    {
        ui.InputLine->setText("");
    }

    ui.InputLine->insert(buttonText);
}

void CalculatorUI::onOperatorInputClicked() // 运算符
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    applyOperatorToken(GetButtonInput(button));
}

void CalculatorUI::onFunctionInputClicked() // 函数
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    applyFunctionToken(GetButtonInput(button));
}

void CalculatorUI::onClearAllClicked() // 全部清除
{
    ui.InputLine->setText("0");
    ui.HistoryLine->clear();
    hasResult = false;
    lastResult = "0";
}

void CalculatorUI::onClearCurrentClicked() // 当前清除
{
    ui.InputLine->setText("0");
    hasResult = false;
}

void CalculatorUI::onBackSpaceClicked() // 回退
{
    if (hasResult)
    {
        ui.InputLine->setText("0");
        hasResult = false;
        return;
    }

    QString text = ui.InputLine->text();
    int pos = ui.InputLine->cursorPosition();

    if (pos <= 0)
    {
        return;
    }

    text.remove(pos - 1, 1);
    ui.InputLine->setText(text);
    ui.InputLine->setCursorPosition(pos - 1);

    if (text.isEmpty())
    {
        ui.InputLine->setText("0");
        ui.InputLine->setCursorPosition(1);
    }
}

void CalculatorUI::onEqualInputClicked() // 等号
{
    QString expression = ui.InputLine->text();
    auto res = cal.process(expression.toStdString());

    if (res.type == Calculator::output_type::ERROR)
    {
        std::string exact_error = res.content;

        ui.InputLine->setText(QString::fromStdString("无效输入"));
        hasResult = true;
        lastResult = "0";
    }
    else if (res.type == Calculator::output_type::POP_UP)
    {
        QMessageBox msg(this);
        msg.setWindowTitle("FeedBack");
        msg.setText(QString::fromStdString(res.content));
        msg.setIcon(QMessageBox::NoIcon);
        msg.setFont(QFont("", 20));
        msg.exec();
        hasResult = false;
    }
    else if (res.type == Calculator::output_type::EQUATION)
    {
        if (!res.egg.empty())
        {
            ShowEggPopup(this, res.egg);
        }

        const QString resultText = ExtractResultText(res.content);
        const QString displayText = ExtractDisplayText(res.content);

        lastResult = resultText;
        const QString historyText = expression + " = " + resultText;

        ui.InputLine->setText(displayText);
        hasResult = true;

        const auto oldFlys = findChildren<QLabel*>("HistoryFlyLabel");
        for (QLabel* oldFly : oldFlys)
        {
            oldFly->deleteLater();
        }

        ui.HistoryLine->clear();

        QLabel* fly = new QLabel(historyText, this);
        fly->setObjectName("HistoryFlyLabel");
        fly->setAttribute(Qt::WA_TransparentForMouseEvents);
        fly->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        fly->setFont(ui.HistoryLine->font());
        fly->setStyleSheet(QString("color:%1; background:transparent;")
            .arg(ui.HistoryLine->palette().color(QPalette::Text).name()));

        const QFont flyFont = ui.HistoryLine->font();
        QFontMetrics fm(flyFont);

        QStyleOptionFrame inOpt;
        inOpt.initFrom(ui.InputLine);
        inOpt.rect = ui.InputLine->rect();

        QStyleOptionFrame hisOpt;
        hisOpt.initFrom(ui.HistoryLine);
        hisOpt.rect = ui.HistoryLine->rect();

        QRect inContent = ui.InputLine->style()->subElementRect(QStyle::SE_LineEditContents, &inOpt, ui.InputLine);
        QRect hisContent = ui.HistoryLine->style()->subElementRect(QStyle::SE_LineEditContents, &hisOpt, ui.HistoryLine);

        inContent.moveTopLeft(ui.InputLine->mapTo(this, inContent.topLeft()));
        hisContent.moveTopLeft(ui.HistoryLine->mapTo(this, hisContent.topLeft()));

        const int textW = qMin(
            qMax(10, fm.tightBoundingRect(historyText).width()),
            qMin(inContent.width(), hisContent.width())
        );
        const int textH = qMin(fm.height(), qMin(inContent.height(), hisContent.height()));

        constexpr int kXNudge = -4;
        constexpr int kYNudge = 0;

        const QRect startRect(
            inContent.right() - textW + kXNudge,
            inContent.center().y() - textH / 2 + kYNudge,
            textW,
            textH
        );

        const QRect endRect(
            hisContent.right() - textW + kXNudge,
            hisContent.center().y() - textH / 2 + kYNudge,
            textW,
            textH
        );

        fly->setFont(flyFont);
        fly->setGeometry(startRect);
        fly->show();
        fly->raise();

        auto* eff = new QGraphicsOpacityEffect(fly);
        eff->setOpacity(0.0);
        fly->setGraphicsEffect(eff);

        auto* moveAnim = new QPropertyAnimation(fly, "geometry", fly);
        moveAnim->setDuration(320);
        moveAnim->setStartValue(startRect);
        moveAnim->setEndValue(endRect);
        moveAnim->setEasingCurve(QEasingCurve::InOutCubic);

        auto* fadeAnim = new QPropertyAnimation(eff, "opacity", fly);
        fadeAnim->setDuration(320);
        fadeAnim->setStartValue(0.0);
        fadeAnim->setEndValue(1.0);
        fadeAnim->setEasingCurve(QEasingCurve::InOutSine);

        auto* group = new QParallelAnimationGroup(fly);
        group->addAnimation(moveAnim);
        group->addAnimation(fadeAnim);

        connect(group, &QParallelAnimationGroup::finished, this, [this, fly, historyText]()
            {
                ui.HistoryLine->setText(historyText);
                fly->deleteLater();
            });

        group->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void CalculatorUI::onScientificTrigBarClicked() // 三角函数菜单
{
    QMenu menu(this);
    menu.setStyleSheet(
        "QMenu{background:#1f1f1f; border:1px solid #3a3a3a;}"
    );

    QString picked;

    auto* panel = new QWidget(&menu);
    panel->setStyleSheet("background:transparent;");
    auto* grid = new QGridLayout(panel);
    grid->setContentsMargins(6, 6, 6, 6);
    grid->setHorizontalSpacing(2);
    grid->setVerticalSpacing(2);

    auto makeBtn = [&](const QString& text, int r, int c)
        {
            auto* b = new QPushButton(text, panel);
            b->setMinimumSize(84, 36);
            b->setStyleSheet(
                "QPushButton{"
                "background:#3f4349; color:#f2f2f2; border:none; border-radius:4px; font-size:18px;}"
                "QPushButton:hover{background:#4a4f56;}"
                "QPushButton:pressed{background:#575d65;}"
            );
            connect(b, &QPushButton::clicked, &menu, [&, text]()
                {
                    picked = text;
                    menu.close();
                });
            grid->addWidget(b, r, c);
        };

    makeBtn("sin", 0, 0);
    makeBtn("cos", 0, 1);
    makeBtn("tan", 0, 2);

    makeBtn("asin", 1, 0);
    makeBtn("acos", 1, 1);
    makeBtn("atan", 1, 2);

    makeBtn("sec", 2, 0);
    makeBtn("csc", 2, 1);
    makeBtn("cot", 2, 2);

    auto* wa = new QWidgetAction(&menu);
    wa->setDefaultWidget(panel);
    menu.addAction(wa);

    menu.exec(ui.pushButton_triangle_function->mapToGlobal(
        QPoint(0, ui.pushButton_triangle_function->height())));

    if (!picked.isEmpty())
    {
        applyFunctionToken(picked);
    }
}

void CalculatorUI::onScientificMoreFuncBarClicked() // 更多函数菜单
{
    QMenu menu(this);
    menu.setStyleSheet(
        "QMenu{background:#1f1f1f; border:1px solid #3a3a3a;}"
    );

    QString picked;

    auto* panel = new QWidget(&menu);
    panel->setStyleSheet("background:transparent;");
    auto* grid = new QGridLayout(panel);
    grid->setContentsMargins(6, 6, 6, 6);
    grid->setHorizontalSpacing(2);
    grid->setVerticalSpacing(2);

    auto makeBtn = [&](const QString& text, int r, int c)
        {
            auto* b = new QPushButton(text, panel);
            b->setMinimumSize(84, 36);
            b->setStyleSheet(
                "QPushButton{"
                "background:#3f4349; color:#f2f2f2; border:none; border-radius:4px; font-size:18px;}"
                "QPushButton:hover{background:#4a4f56;}"
                "QPushButton:pressed{background:#575d65;}"
            );
            connect(b, &QPushButton::clicked, &menu, [&, text]()
                {
                    picked = text;
                    menu.close();
                });
            grid->addWidget(b, r, c);
        };

    makeBtn("floor", 0, 0);
    makeBtn("round", 0, 1);
    makeBtn("ceil", 0, 2);

    makeBtn("gcd", 1, 0);
    makeBtn("lcm", 1, 1);

    makeBtn("max", 2, 0);
    makeBtn("min", 2, 1);

    makeBtn("log10", 2, 2);
    makeBtn("pow", 1, 2);

    auto* wa = new QWidgetAction(&menu);
    wa->setDefaultWidget(panel);
    menu.addAction(wa);

    menu.exec(ui.pushButton_triangle_function->mapToGlobal(
        QPoint(0, ui.pushButton_triangle_function->height())));

    if (!picked.isEmpty())
    {
        applyFunctionToken(picked);
    }
}

void CalculatorUI::onScientificAngleModeClicked() // 角度切换
{
    scientificDegMode = !scientificDegMode;
    settingState.degMode = scientificDegMode;

    if (scientificDegMode)
    {
        cal.set_deg();
        ui.pushButton_rad_and_deg->setText("Deg");
    }
    else
    {
        cal.set_rad();
        ui.pushButton_rad_and_deg->setText("Rad");
    }
}

// 连接信号槽
void CalculatorUI::connectSignals()
{
    // 标准数字
    const std::initializer_list<QPushButton*> numberButtons = {
        ui.pushButton0, ui.pushButton1, ui.pushButton2, ui.pushButton3, ui.pushButton4,
        ui.pushButton5, ui.pushButton6, ui.pushButton7, ui.pushButton8, ui.pushButton9,
        ui.pushButton_Dot
    };
    for (auto* b : numberButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onNumberInputClicked);
    }

    // 标准运算符
    const std::initializer_list<QPushButton*> opButtons = {
        ui.pushButton_Add, ui.pushButton_Sub, ui.pushButton_Multi, ui.pushButton_Divide, ui.pushButton_Mod
    };
    for (auto* b : opButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onOperatorInputClicked);
    }

    // 标准函数
    const std::initializer_list<QPushButton*> funcButtons = {
        ui.pushButton_Minus, ui.pushButton_Sqrt, ui.pushButton_Square, ui.pushButton_Reciprocal
    };
    for (auto* b : funcButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onFunctionInputClicked);
    }

    // 科学数字
    const std::initializer_list<QPushButton*> sciNumberButtons = {
        ui.pushButton_0_, ui.pushButton_1_, ui.pushButton_2_, ui.pushButton_3_, ui.pushButton_4_,
        ui.pushButton_5_, ui.pushButton_6_, ui.pushButton_7_, ui.pushButton_8_, ui.pushButton_9_,
        ui.pushButton_Point_, ui.pushButton_PI, ui.pushButton_Euler
    };
    for (auto* b : sciNumberButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onNumberInputClicked);
    }

    // 科学运算符
    const std::initializer_list<QPushButton*> sciOpButtons = {
        ui.pushButton_Add_, ui.pushButton_Sub_, ui.pushButton_Multi_, ui.pushButton_Divide_, ui.pushButton_Mod_,
        ui.pushButton_LeftParen, ui.pushButton_RightParen, ui.pushButton_Comma, ui.pushButton_Pow, ui.pushButton_Factorial,
        ui.pushButton_Deg
    };
    for (auto* b : sciOpButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onOperatorInputClicked);
    }

    // 科学函数
    const std::initializer_list<QPushButton*> sciFuncButtons = {
        ui.pushButton_Minus_, ui.pushButton_Sqrt_, ui.pushButton_Square_, ui.pushButton_Reciprocal_,
        ui.pushButton_Log, ui.pushButton_Ln, ui.pushButton_Abs, ui.pushButton_Exe
    };
    for (auto* b : sciFuncButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onFunctionInputClicked);
    }

    // 程序员数字
    const std::initializer_list<QPushButton*> progNumberButtons = {
        ui.pushButton___0, ui.pushButton___1, ui.pushButton___2, ui.pushButton___3, ui.pushButton___4,
        ui.pushButton___5, ui.pushButton___6, ui.pushButton___7, ui.pushButton___8, ui.pushButton___9,
        ui.pushButton___Point
    };
    for (auto* b : progNumberButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onNumberInputClicked);
    }

    // 程序员运算符
    const std::initializer_list<QPushButton*> progOpButtons = {
        ui.pushButton___Add, ui.pushButton___Sub, ui.pushButton___Multi, ui.pushButton___Divide,
        ui.pushButton___LeftParen, ui.pushButton___RightParen,
        ui.pushButton_OR, ui.pushButton_AND, ui.pushButton_XOR
    };
    for (auto* b : progOpButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onOperatorInputClicked);
    }

    // 程序员函数
    const std::initializer_list<QPushButton*> progFuncButtons = {
        ui.pushButton___Minus
    };
    for (auto* b : progFuncButtons)
    {
        connect(b, &QPushButton::clicked, this, &CalculatorUI::onFunctionInputClicked);
    }

    // 功能键(标准)
    connect(ui.pushButton_ClearAll, &QPushButton::clicked, this, &CalculatorUI::onClearAllClicked);
    connect(ui.pushButton_ClearCurrent, &QPushButton::clicked, this, &CalculatorUI::onClearCurrentClicked);
    connect(ui.pushButton_Equal, &QPushButton::clicked, this, &CalculatorUI::onEqualInputClicked);
    connect(ui.pushButton_BackSpace, &QPushButton::clicked, this, &CalculatorUI::onBackSpaceClicked);

    // 功能键(科学)
    connect(ui.pushButton_Clear_, &QPushButton::clicked, this, &CalculatorUI::onClearAllClicked);
    connect(ui.pushButton_Delet_, &QPushButton::clicked, this, &CalculatorUI::onBackSpaceClicked);
    connect(ui.pushButton_Equal_, &QPushButton::clicked, this, &CalculatorUI::onEqualInputClicked);
    connect(ui.pushButton_triangle_function, &QPushButton::clicked, this, &CalculatorUI::onScientificTrigBarClicked);
    connect(ui.pushButton_more_function, &QPushButton::clicked, this, &CalculatorUI::onScientificMoreFuncBarClicked);
    connect(ui.pushButton_rad_and_deg, &QPushButton::clicked, this, &CalculatorUI::onScientificAngleModeClicked);

    // 功能键(程序员)
    connect(ui.pushButton___Clear, &QPushButton::clicked, this, &CalculatorUI::onClearAllClicked);
    connect(ui.pushButton___Equal, &QPushButton::clicked, this, &CalculatorUI::onEqualInputClicked);
    connect(ui.pushButton___BackSpace, &QPushButton::clicked, this, &CalculatorUI::onBackSpaceClicked);

    // 头部工具
    connect(ui.pushButton_StayOnTop, &QPushButton::clicked, this, &CalculatorUI::onStayOnTopClicked);
    connect(ui.pushButton_Minimum, &QPushButton::clicked, this, &CalculatorUI::onMinimumClicked);
    connect(ui.pushButton_Maximum, &QPushButton::clicked, this, &CalculatorUI::onMaximumClicked);
    connect(ui.pushButton_Exit, &QPushButton::clicked, this, &CalculatorUI::onExitClicked);

    // 功能工具
    connect(ui.pushButton_Help, &QPushButton::clicked, this, &CalculatorUI::onHelpClicked);
    connect(ui.pushButton_History, &QPushButton::clicked, this, &CalculatorUI::onHistoryClicked);
    connect(ui.pushButton_Setting, &QPushButton::clicked, this, &CalculatorUI::onSettingClicked);
    connect(ui.pushButton_Sonpages, &QPushButton::clicked, this, &CalculatorUI::onSonpagesClicked);
    connect(ui.InputLine, &QLineEdit::returnPressed, ui.pushButton_Equal, &QPushButton::click);
}

// 设置信号槽输入内容
void CalculatorUI::setupInputProperties()
{
    // 标准
    ui.pushButton_Multi->setProperty("input", "*");
    ui.pushButton_Add->setProperty("input", "+");
    ui.pushButton_Divide->setProperty("input", "/");
    ui.pushButton_Mod->setProperty("input", "%");
    ui.pushButton_Sub->setProperty("input", "-");
    ui.pushButton_Sqrt->setProperty("input", "sqrt");
    ui.pushButton_Minus->setProperty("input", "-");
    ui.pushButton_Square->setProperty("input", "square");
    ui.pushButton_Reciprocal->setProperty("input", "reciprocal");

    // 科学
    ui.pushButton_Multi_->setProperty("input", "*");
    ui.pushButton_Add_->setProperty("input", "+");
    ui.pushButton_Divide_->setProperty("input", "/");
    ui.pushButton_Mod_->setProperty("input", "%");
    ui.pushButton_Sub_->setProperty("input", "-");
    ui.pushButton_LeftParen->setProperty("input", "(");
    ui.pushButton_RightParen->setProperty("input", ")");
    ui.pushButton_Comma->setProperty("input", ",");
    ui.pushButton_Pow->setProperty("input", "^");
    ui.pushButton_Factorial->setProperty("input", "!");
    ui.pushButton_Deg->setProperty("input", "deg");
    ui.pushButton_Sqrt_->setProperty("input", "sqrt");
    ui.pushButton_Minus_->setProperty("input", "-");
    ui.pushButton_Square_->setProperty("input", "square");
    ui.pushButton_Reciprocal_->setProperty("input", "reciprocal");
    ui.pushButton_Log->setProperty("input", "log");
    ui.pushButton_Ln->setProperty("input", "ln");
    ui.pushButton_Abs->setProperty("input", "abs");
    ui.pushButton_Exe->setProperty("input", "exp");
    ui.pushButton_Point_->setProperty("input", ".");
    ui.pushButton_PI->setProperty("input", "pi");
    ui.pushButton_Euler->setProperty("input", "e");

    // 程序员
    ui.pushButton___Multi->setProperty("input", "*");
    ui.pushButton___Add->setProperty("input", "+");
    ui.pushButton___Divide->setProperty("input", "/");
    ui.pushButton___Sub->setProperty("input", "-");
    ui.pushButton___Minus->setProperty("input", "-");
    ui.pushButton___LeftParen->setProperty("input", "(");
    ui.pushButton___RightParen->setProperty("input", ")");
    ui.pushButton___Point->setProperty("input", ".");
    ui.pushButton_XOR->setProperty("input", "~");
    ui.pushButton_OR->setProperty("input", "|");
    ui.pushButton_AND->setProperty("input", "&");
}