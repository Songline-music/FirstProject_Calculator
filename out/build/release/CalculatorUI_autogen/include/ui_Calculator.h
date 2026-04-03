/********************************************************************************
** Form generated from reading UI file 'Calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorUIClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *calculatorBody;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *HeadLine;
    QLabel *Name;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_StayOnTop;
    QPushButton *pushButton_Minimum;
    QPushButton *pushButton_Maximum;
    QPushButton *pushButton_Exit;
    QHBoxLayout *FunctionLine;
    QPushButton *pushButton_Sonpages;
    QPushButton *pushButton_Setting;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Help;
    QPushButton *pushButton_History;
    QSpacerItem *verticalSpacer;
    QLineEdit *HistoryLine;
    QLineEdit *InputLine;
    QStackedWidget *KeyStack;
    QWidget *PageStandard;
    QGridLayout *key;
    QPushButton *pushButton0;
    QPushButton *pushButton7;
    QPushButton *pushButton_Dot;
    QPushButton *pushButton9;
    QPushButton *pushButton6;
    QPushButton *pushButton_Minus;
    QPushButton *pushButton_Equal;
    QPushButton *pushButton_Sqrt;
    QPushButton *pushButton5;
    QPushButton *pushButton8;
    QPushButton *pushButton_Multi;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_BackSpace;
    QPushButton *pushButton_ClearAll;
    QPushButton *pushButton3;
    QPushButton *pushButton_Mod;
    QPushButton *pushButton_ClearCurrent;
    QPushButton *pushButton2;
    QPushButton *pushButton4;
    QPushButton *pushButton1;
    QPushButton *pushButton_Divide;
    QPushButton *pushButton_Square;
    QPushButton *pushButton_Reciprocal;
    QPushButton *pushButton_Sub;
    QWidget *PageScientific;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *Key_Head;
    QPushButton *pushButton_triangle_function;
    QPushButton *pushButton_more_function;
    QPushButton *pushButton_rad_and_deg;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *Key_Back;
    QPushButton *pushButton_LeftParen;
    QPushButton *pushButton_Equal_;
    QPushButton *pushButton_6_;
    QPushButton *pushButton_Factorial;
    QPushButton *pushButton_Deg;
    QPushButton *pushButton_4_;
    QPushButton *pushButton_Comma;
    QPushButton *pushButton_Minus_;
    QPushButton *pushButton_RightParen;
    QPushButton *pushButton_Add_;
    QPushButton *pushButton_1_;
    QPushButton *pushButton_Log;
    QPushButton *pushButton_7_;
    QPushButton *pushButton_3_;
    QPushButton *pushButton_Multi_;
    QPushButton *pushButton_Sqrt_;
    QPushButton *pushButton_Pow;
    QPushButton *pushButton_9_;
    QPushButton *pushButton_PI;
    QPushButton *pushButton_Divide_;
    QPushButton *pushButton_2_;
    QPushButton *pushButton_Sub_;
    QPushButton *pushButton_Point_;
    QPushButton *pushButton_Reciprocal_;
    QPushButton *pushButton_Abs;
    QPushButton *pushButton_Mod_;
    QPushButton *pushButton_Euler;
    QPushButton *pushButton_0_;
    QPushButton *pushButton_5_;
    QPushButton *pushButton_Square_;
    QPushButton *pushButton_Clear_;
    QPushButton *pushButton_Exe;
    QPushButton *pushButton_Delet_;
    QPushButton *pushButton_8_;
    QPushButton *pushButton_Ln;
    QWidget *PageProgrammer;
    QGridLayout *gridLayout;
    QPushButton *pushButton___LeftParen;
    QPushButton *pushButton___RightParen;
    QPushButton *pushButton___Clear;
    QPushButton *pushButton___BackSpace;
    QPushButton *pushButton_AND;
    QPushButton *pushButton_OR;
    QPushButton *pushButton_XOR;
    QPushButton *pushButton___Divide;
    QPushButton *pushButton___7;
    QPushButton *pushButton___8;
    QPushButton *pushButton___9;
    QPushButton *pushButton___Multi;
    QPushButton *pushButton___4;
    QPushButton *pushButton___5;
    QPushButton *pushButton___6;
    QPushButton *pushButton___Sub;
    QPushButton *pushButton___1;
    QPushButton *pushButton___2;
    QPushButton *pushButton___3;
    QPushButton *pushButton___Add;
    QPushButton *pushButton___Minus;
    QPushButton *pushButton___0;
    QPushButton *pushButton___Point;
    QPushButton *pushButton___Equal;

    void setupUi(QWidget *CalculatorUIClass)
    {
        if (CalculatorUIClass->objectName().isEmpty())
            CalculatorUIClass->setObjectName("CalculatorUIClass");
        CalculatorUIClass->resize(403, 660);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalculatorUIClass->sizePolicy().hasHeightForWidth());
        CalculatorUIClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(25);
        CalculatorUIClass->setFont(font);
        CalculatorUIClass->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background-color: #2d2d2d;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(CalculatorUIClass);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        calculatorBody = new QWidget(CalculatorUIClass);
        calculatorBody->setObjectName("calculatorBody");
        sizePolicy.setHeightForWidth(calculatorBody->sizePolicy().hasHeightForWidth());
        calculatorBody->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(calculatorBody);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 0, 5, 5);
        HeadLine = new QHBoxLayout();
        HeadLine->setSpacing(6);
        HeadLine->setObjectName("HeadLine");
        Name = new QLabel(calculatorBody);
        Name->setObjectName("Name");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setStrikeOut(false);
        Name->setFont(font1);
        Name->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Name->setMargin(5);

        HeadLine->addWidget(Name);

        horizontalSpacer_2 = new QSpacerItem(380, 50, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        HeadLine->addItem(horizontalSpacer_2);

        pushButton_StayOnTop = new QPushButton(calculatorBody);
        pushButton_StayOnTop->setObjectName("pushButton_StayOnTop");
        pushButton_StayOnTop->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemLockScreen));
        pushButton_StayOnTop->setIcon(icon);
        pushButton_StayOnTop->setIconSize(QSize(20, 19));

        HeadLine->addWidget(pushButton_StayOnTop);

        pushButton_Minimum = new QPushButton(calculatorBody);
        pushButton_Minimum->setObjectName("pushButton_Minimum");
        pushButton_Minimum->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove));
        pushButton_Minimum->setIcon(icon1);
        pushButton_Minimum->setIconSize(QSize(20, 20));

        HeadLine->addWidget(pushButton_Minimum);

        pushButton_Maximum = new QPushButton(calculatorBody);
        pushButton_Maximum->setObjectName("pushButton_Maximum");
        pushButton_Maximum->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStop));
        pushButton_Maximum->setIcon(icon2);
        pushButton_Maximum->setIconSize(QSize(15, 15));

        HeadLine->addWidget(pushButton_Maximum);

        pushButton_Exit = new QPushButton(calculatorBody);
        pushButton_Exit->setObjectName("pushButton_Exit");
        pushButton_Exit->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        pushButton_Exit->setIcon(icon3);
        pushButton_Exit->setIconSize(QSize(20, 20));

        HeadLine->addWidget(pushButton_Exit);


        verticalLayout->addLayout(HeadLine);

        FunctionLine = new QHBoxLayout();
        FunctionLine->setSpacing(6);
        FunctionLine->setObjectName("FunctionLine");
        pushButton_Sonpages = new QPushButton(calculatorBody);
        pushButton_Sonpages->setObjectName("pushButton_Sonpages");
        pushButton_Sonpages->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Sonpages\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton#pushButton_Sonpages:hover\n"
"{\n"
"    background-color: rgba(255,255,255,0.04);\n"
"}\n"
"QPushButton#pushButton_Sonpages:pressed {\n"
"    background-color: rgba(255,255,255,0.08);\n"
"}\n"
"QPushButton#pushButton_Sonpages:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyLeft));
        pushButton_Sonpages->setIcon(icon4);
        pushButton_Sonpages->setIconSize(QSize(20, 20));

        FunctionLine->addWidget(pushButton_Sonpages);

        pushButton_Setting = new QPushButton(calculatorBody);
        pushButton_Setting->setObjectName("pushButton_Setting");
        pushButton_Setting->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Setting\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton#pushButton_Setting:hover\n"
"{\n"
"    background-color: rgba(255,255,255,0.04);\n"
"}\n"
"QPushButton#pushButton_Setting:pressed {\n"
"    background-color: rgba(255,255,255,0.08);\n"
"}\n"
"QPushButton#pushButton_Setting:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        pushButton_Setting->setIcon(icon5);
        pushButton_Setting->setIconSize(QSize(20, 20));

        FunctionLine->addWidget(pushButton_Setting);

        horizontalSpacer = new QSpacerItem(320, 50, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        FunctionLine->addItem(horizontalSpacer);

        pushButton_Help = new QPushButton(calculatorBody);
        pushButton_Help->setObjectName("pushButton_Help");
        pushButton_Help->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Help\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton#pushButton_Help:hover\n"
"{\n"
"    background-color: rgba(255,255,255,0.04);\n"
"}\n"
"QPushButton#pushButton_Help:pressed {\n"
"    background-color: rgba(255,255,255,0.08);\n"
"}\n"
"QPushButton#pushButton_Help:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq));
        pushButton_Help->setIcon(icon6);
        pushButton_Help->setIconSize(QSize(20, 20));

        FunctionLine->addWidget(pushButton_Help);

        pushButton_History = new QPushButton(calculatorBody);
        pushButton_History->setObjectName("pushButton_History");
        pushButton_History->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_History\n"
"{\n"
"    background-color: transparent;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton#pushButton_History:hover\n"
"{\n"
"    background-color: rgba(255,255,255,0.04);\n"
"}\n"
"QPushButton#pushButton_History:pressed {\n"
"    background-color: rgba(255,255,255,0.08);\n"
"}\n"
"QPushButton#pushButton_History:focus\n"
"{\n"
"    outline: none;\n"
"}"));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpenRecent));
        pushButton_History->setIcon(icon7);
        pushButton_History->setIconSize(QSize(20, 20));

        FunctionLine->addWidget(pushButton_History);


        verticalLayout->addLayout(FunctionLine);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        HistoryLine = new QLineEdit(calculatorBody);
        HistoryLine->setObjectName("HistoryLine");
        HistoryLine->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(HistoryLine->sizePolicy().hasHeightForWidth());
        HistoryLine->setSizePolicy(sizePolicy1);
        HistoryLine->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setStrikeOut(false);
        HistoryLine->setFont(font2);
        HistoryLine->setStyleSheet(QString::fromUtf8("QLineEdit#HistoryLine\n"
"{\n"
"    background-color: #2d2d2d;\n"
"    color: #aaaaaa;\n"
"    border: none;\n"
"    padding: 10px;\n"
"    margin: 0;\n"
"    font-size: 16px;\n"
"    text-align: right;\n"
"}\n"
"QLineEdit#HistoryLine:focus\n"
"{\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        HistoryLine->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        HistoryLine->setReadOnly(true);

        verticalLayout->addWidget(HistoryLine);

        InputLine = new QLineEdit(calculatorBody);
        InputLine->setObjectName("InputLine");
        sizePolicy1.setHeightForWidth(InputLine->sizePolicy().hasHeightForWidth());
        InputLine->setSizePolicy(sizePolicy1);
        InputLine->setMinimumSize(QSize(0, 100));
        QFont font3;
        font3.setBold(true);
        font3.setStrikeOut(false);
        InputLine->setFont(font3);
        InputLine->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        InputLine->setStyleSheet(QString::fromUtf8("QLineEdit#InputLine\n"
"{\n"
"    background-color: #2d2d2d;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    padding: 20px 10px 20px 20px;\n"
"    margin: 0;\n"
"    font-size: 50px;\n"
"    text-align: right;\n"
"}\n"
"QLineEdit#InputLine:focus\n"
"{\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        InputLine->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        InputLine->setReadOnly(false);

        verticalLayout->addWidget(InputLine);

        KeyStack = new QStackedWidget(calculatorBody);
        KeyStack->setObjectName("KeyStack");
        sizePolicy.setHeightForWidth(KeyStack->sizePolicy().hasHeightForWidth());
        KeyStack->setSizePolicy(sizePolicy);
        KeyStack->setLineWidth(0);
        PageStandard = new QWidget();
        PageStandard->setObjectName("PageStandard");
        sizePolicy.setHeightForWidth(PageStandard->sizePolicy().hasHeightForWidth());
        PageStandard->setSizePolicy(sizePolicy);
        key = new QGridLayout(PageStandard);
        key->setSpacing(2);
        key->setContentsMargins(11, 11, 11, 11);
        key->setObjectName("key");
        key->setContentsMargins(0, 0, 0, 0);
        pushButton0 = new QPushButton(PageStandard);
        pushButton0->setObjectName("pushButton0");
        sizePolicy.setHeightForWidth(pushButton0->sizePolicy().hasHeightForWidth());
        pushButton0->setSizePolicy(sizePolicy);
        pushButton0->setMinimumSize(QSize(30, 30));
        QFont font4;
        pushButton0->setFont(font4);
        pushButton0->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton0, 5, 1, 1, 1);

        pushButton7 = new QPushButton(PageStandard);
        pushButton7->setObjectName("pushButton7");
        sizePolicy.setHeightForWidth(pushButton7->sizePolicy().hasHeightForWidth());
        pushButton7->setSizePolicy(sizePolicy);
        pushButton7->setMinimumSize(QSize(30, 30));
        pushButton7->setFont(font4);
        pushButton7->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton7, 2, 0, 1, 1);

        pushButton_Dot = new QPushButton(PageStandard);
        pushButton_Dot->setObjectName("pushButton_Dot");
        sizePolicy.setHeightForWidth(pushButton_Dot->sizePolicy().hasHeightForWidth());
        pushButton_Dot->setSizePolicy(sizePolicy);
        pushButton_Dot->setMinimumSize(QSize(30, 30));
        pushButton_Dot->setFont(font4);
        pushButton_Dot->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton_Dot, 5, 2, 1, 1);

        pushButton9 = new QPushButton(PageStandard);
        pushButton9->setObjectName("pushButton9");
        sizePolicy.setHeightForWidth(pushButton9->sizePolicy().hasHeightForWidth());
        pushButton9->setSizePolicy(sizePolicy);
        pushButton9->setMinimumSize(QSize(30, 30));
        pushButton9->setFont(font4);
        pushButton9->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton9, 2, 2, 1, 1);

        pushButton6 = new QPushButton(PageStandard);
        pushButton6->setObjectName("pushButton6");
        sizePolicy.setHeightForWidth(pushButton6->sizePolicy().hasHeightForWidth());
        pushButton6->setSizePolicy(sizePolicy);
        pushButton6->setMinimumSize(QSize(30, 30));
        pushButton6->setFont(font4);
        pushButton6->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton6, 3, 2, 1, 1);

        pushButton_Minus = new QPushButton(PageStandard);
        pushButton_Minus->setObjectName("pushButton_Minus");
        sizePolicy.setHeightForWidth(pushButton_Minus->sizePolicy().hasHeightForWidth());
        pushButton_Minus->setSizePolicy(sizePolicy);
        pushButton_Minus->setMinimumSize(QSize(30, 30));
        pushButton_Minus->setFont(font4);
        pushButton_Minus->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton_Minus, 5, 0, 1, 1);

        pushButton_Equal = new QPushButton(PageStandard);
        pushButton_Equal->setObjectName("pushButton_Equal");
        sizePolicy.setHeightForWidth(pushButton_Equal->sizePolicy().hasHeightForWidth());
        pushButton_Equal->setSizePolicy(sizePolicy);
        pushButton_Equal->setMinimumSize(QSize(30, 30));
        pushButton_Equal->setFont(font4);
        pushButton_Equal->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #f0f0f0;\n"
"    color: #333333;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #e5e5e5;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #d5d5d5;\n"
"}"));

        key->addWidget(pushButton_Equal, 5, 3, 1, 1);

        pushButton_Sqrt = new QPushButton(PageStandard);
        pushButton_Sqrt->setObjectName("pushButton_Sqrt");
        sizePolicy.setHeightForWidth(pushButton_Sqrt->sizePolicy().hasHeightForWidth());
        pushButton_Sqrt->setSizePolicy(sizePolicy);
        pushButton_Sqrt->setMinimumSize(QSize(30, 30));
        pushButton_Sqrt->setFont(font4);
        pushButton_Sqrt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Sqrt, 1, 2, 1, 1);

        pushButton5 = new QPushButton(PageStandard);
        pushButton5->setObjectName("pushButton5");
        sizePolicy.setHeightForWidth(pushButton5->sizePolicy().hasHeightForWidth());
        pushButton5->setSizePolicy(sizePolicy);
        pushButton5->setMinimumSize(QSize(30, 30));
        pushButton5->setFont(font4);
        pushButton5->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton5, 3, 1, 1, 1);

        pushButton8 = new QPushButton(PageStandard);
        pushButton8->setObjectName("pushButton8");
        sizePolicy.setHeightForWidth(pushButton8->sizePolicy().hasHeightForWidth());
        pushButton8->setSizePolicy(sizePolicy);
        pushButton8->setMinimumSize(QSize(30, 30));
        pushButton8->setFont(font4);
        pushButton8->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton8, 2, 1, 1, 1);

        pushButton_Multi = new QPushButton(PageStandard);
        pushButton_Multi->setObjectName("pushButton_Multi");
        sizePolicy.setHeightForWidth(pushButton_Multi->sizePolicy().hasHeightForWidth());
        pushButton_Multi->setSizePolicy(sizePolicy);
        pushButton_Multi->setMinimumSize(QSize(30, 30));
        pushButton_Multi->setFont(font4);
        pushButton_Multi->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Multi, 2, 3, 1, 1);

        pushButton_Add = new QPushButton(PageStandard);
        pushButton_Add->setObjectName("pushButton_Add");
        sizePolicy.setHeightForWidth(pushButton_Add->sizePolicy().hasHeightForWidth());
        pushButton_Add->setSizePolicy(sizePolicy);
        pushButton_Add->setMinimumSize(QSize(30, 30));
        pushButton_Add->setFont(font4);
        pushButton_Add->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Add, 4, 3, 1, 1);

        pushButton_BackSpace = new QPushButton(PageStandard);
        pushButton_BackSpace->setObjectName("pushButton_BackSpace");
        sizePolicy.setHeightForWidth(pushButton_BackSpace->sizePolicy().hasHeightForWidth());
        pushButton_BackSpace->setSizePolicy(sizePolicy);
        pushButton_BackSpace->setMinimumSize(QSize(30, 30));
        pushButton_BackSpace->setFont(font4);
        pushButton_BackSpace->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_BackSpace, 0, 3, 1, 1);

        pushButton_ClearAll = new QPushButton(PageStandard);
        pushButton_ClearAll->setObjectName("pushButton_ClearAll");
        sizePolicy.setHeightForWidth(pushButton_ClearAll->sizePolicy().hasHeightForWidth());
        pushButton_ClearAll->setSizePolicy(sizePolicy);
        pushButton_ClearAll->setMinimumSize(QSize(30, 30));
        pushButton_ClearAll->setFont(font4);
        pushButton_ClearAll->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_ClearAll, 0, 2, 1, 1);

        pushButton3 = new QPushButton(PageStandard);
        pushButton3->setObjectName("pushButton3");
        sizePolicy.setHeightForWidth(pushButton3->sizePolicy().hasHeightForWidth());
        pushButton3->setSizePolicy(sizePolicy);
        pushButton3->setMinimumSize(QSize(30, 30));
        pushButton3->setFont(font4);
        pushButton3->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton3, 4, 2, 1, 1);

        pushButton_Mod = new QPushButton(PageStandard);
        pushButton_Mod->setObjectName("pushButton_Mod");
        sizePolicy.setHeightForWidth(pushButton_Mod->sizePolicy().hasHeightForWidth());
        pushButton_Mod->setSizePolicy(sizePolicy);
        pushButton_Mod->setMinimumSize(QSize(30, 30));
        pushButton_Mod->setFont(font4);
        pushButton_Mod->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Mod, 0, 0, 1, 1);

        pushButton_ClearCurrent = new QPushButton(PageStandard);
        pushButton_ClearCurrent->setObjectName("pushButton_ClearCurrent");
        sizePolicy.setHeightForWidth(pushButton_ClearCurrent->sizePolicy().hasHeightForWidth());
        pushButton_ClearCurrent->setSizePolicy(sizePolicy);
        pushButton_ClearCurrent->setMinimumSize(QSize(30, 30));
        pushButton_ClearCurrent->setFont(font4);
        pushButton_ClearCurrent->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_ClearCurrent, 0, 1, 1, 1);

        pushButton2 = new QPushButton(PageStandard);
        pushButton2->setObjectName("pushButton2");
        sizePolicy.setHeightForWidth(pushButton2->sizePolicy().hasHeightForWidth());
        pushButton2->setSizePolicy(sizePolicy);
        pushButton2->setMinimumSize(QSize(30, 30));
        pushButton2->setFont(font4);
        pushButton2->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton2, 4, 1, 1, 1);

        pushButton4 = new QPushButton(PageStandard);
        pushButton4->setObjectName("pushButton4");
        sizePolicy.setHeightForWidth(pushButton4->sizePolicy().hasHeightForWidth());
        pushButton4->setSizePolicy(sizePolicy);
        pushButton4->setMinimumSize(QSize(30, 30));
        pushButton4->setFont(font4);
        pushButton4->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton4, 3, 0, 1, 1);

        pushButton1 = new QPushButton(PageStandard);
        pushButton1->setObjectName("pushButton1");
        sizePolicy.setHeightForWidth(pushButton1->sizePolicy().hasHeightForWidth());
        pushButton1->setSizePolicy(sizePolicy);
        pushButton1->setMinimumSize(QSize(30, 30));
        pushButton1->setFont(font4);
        pushButton1->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        key->addWidget(pushButton1, 4, 0, 1, 1);

        pushButton_Divide = new QPushButton(PageStandard);
        pushButton_Divide->setObjectName("pushButton_Divide");
        sizePolicy.setHeightForWidth(pushButton_Divide->sizePolicy().hasHeightForWidth());
        pushButton_Divide->setSizePolicy(sizePolicy);
        pushButton_Divide->setMinimumSize(QSize(30, 30));
        pushButton_Divide->setFont(font4);
        pushButton_Divide->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Divide, 1, 3, 1, 1);

        pushButton_Square = new QPushButton(PageStandard);
        pushButton_Square->setObjectName("pushButton_Square");
        sizePolicy.setHeightForWidth(pushButton_Square->sizePolicy().hasHeightForWidth());
        pushButton_Square->setSizePolicy(sizePolicy);
        pushButton_Square->setMinimumSize(QSize(30, 30));
        pushButton_Square->setFont(font4);
        pushButton_Square->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Square, 1, 1, 1, 1);

        pushButton_Reciprocal = new QPushButton(PageStandard);
        pushButton_Reciprocal->setObjectName("pushButton_Reciprocal");
        sizePolicy.setHeightForWidth(pushButton_Reciprocal->sizePolicy().hasHeightForWidth());
        pushButton_Reciprocal->setSizePolicy(sizePolicy);
        pushButton_Reciprocal->setMinimumSize(QSize(30, 30));
        pushButton_Reciprocal->setFont(font4);
        pushButton_Reciprocal->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Reciprocal, 1, 0, 1, 1);

        pushButton_Sub = new QPushButton(PageStandard);
        pushButton_Sub->setObjectName("pushButton_Sub");
        sizePolicy.setHeightForWidth(pushButton_Sub->sizePolicy().hasHeightForWidth());
        pushButton_Sub->setSizePolicy(sizePolicy);
        pushButton_Sub->setMinimumSize(QSize(30, 30));
        pushButton_Sub->setFont(font4);
        pushButton_Sub->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        key->addWidget(pushButton_Sub, 3, 3, 1, 1);

        KeyStack->addWidget(PageStandard);
        PageScientific = new QWidget();
        PageScientific->setObjectName("PageScientific");
        sizePolicy.setHeightForWidth(PageScientific->sizePolicy().hasHeightForWidth());
        PageScientific->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(PageScientific);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Key_Head = new QHBoxLayout();
        Key_Head->setSpacing(1);
        Key_Head->setObjectName("Key_Head");
        pushButton_triangle_function = new QPushButton(PageScientific);
        pushButton_triangle_function->setObjectName("pushButton_triangle_function");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_triangle_function->sizePolicy().hasHeightForWidth());
        pushButton_triangle_function->setSizePolicy(sizePolicy2);
        pushButton_triangle_function->setMinimumSize(QSize(60, 40));
        pushButton_triangle_function->setFont(font4);
        pushButton_triangle_function->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgba(255,255,255,0.04);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255,255,255,0.08);\n"
"}\n"
"QPushButton:focus\n"
"{\n"
"    outline: none;\n"
"}"));

        Key_Head->addWidget(pushButton_triangle_function);

        pushButton_more_function = new QPushButton(PageScientific);
        pushButton_more_function->setObjectName("pushButton_more_function");
        sizePolicy2.setHeightForWidth(pushButton_more_function->sizePolicy().hasHeightForWidth());
        pushButton_more_function->setSizePolicy(sizePolicy2);
        pushButton_more_function->setMinimumSize(QSize(60, 40));
        pushButton_more_function->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgba(255,255,255,0.04);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255,255,255,0.08);\n"
"}\n"
"QPushButton:focus\n"
"{\n"
"    outline: none;\n"
"}"));

        Key_Head->addWidget(pushButton_more_function);

        pushButton_rad_and_deg = new QPushButton(PageScientific);
        pushButton_rad_and_deg->setObjectName("pushButton_rad_and_deg");
        sizePolicy2.setHeightForWidth(pushButton_rad_and_deg->sizePolicy().hasHeightForWidth());
        pushButton_rad_and_deg->setSizePolicy(sizePolicy2);
        pushButton_rad_and_deg->setMinimumSize(QSize(50, 40));
        pushButton_rad_and_deg->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    padding: 4px;\n"
"    border-radius: 4px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgba(255,255,255,0.04);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255,255,255,0.08);\n"
"}\n"
"QPushButton:focus\n"
"{\n"
"    outline: none;\n"
"}"));

        Key_Head->addWidget(pushButton_rad_and_deg);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        Key_Head->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(Key_Head);

        Key_Back = new QGridLayout();
        Key_Back->setSpacing(2);
        Key_Back->setObjectName("Key_Back");
        Key_Back->setContentsMargins(0, 0, 0, 0);
        pushButton_LeftParen = new QPushButton(PageScientific);
        pushButton_LeftParen->setObjectName("pushButton_LeftParen");
        sizePolicy.setHeightForWidth(pushButton_LeftParen->sizePolicy().hasHeightForWidth());
        pushButton_LeftParen->setSizePolicy(sizePolicy);
        pushButton_LeftParen->setFont(font4);
        pushButton_LeftParen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_LeftParen, 2, 2, 1, 1);

        pushButton_Equal_ = new QPushButton(PageScientific);
        pushButton_Equal_->setObjectName("pushButton_Equal_");
        sizePolicy.setHeightForWidth(pushButton_Equal_->sizePolicy().hasHeightForWidth());
        pushButton_Equal_->setSizePolicy(sizePolicy);
        pushButton_Equal_->setFont(font4);
        pushButton_Equal_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #f0f0f0;\n"
"    color: #333333;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #e5e5e5;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #d5d5d5;\n"
"}"));

        Key_Back->addWidget(pushButton_Equal_, 7, 6, 1, 1);

        pushButton_6_ = new QPushButton(PageScientific);
        pushButton_6_->setObjectName("pushButton_6_");
        sizePolicy.setHeightForWidth(pushButton_6_->sizePolicy().hasHeightForWidth());
        pushButton_6_->setSizePolicy(sizePolicy);
        pushButton_6_->setFont(font4);
        pushButton_6_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_6_, 5, 5, 1, 1);

        pushButton_Factorial = new QPushButton(PageScientific);
        pushButton_Factorial->setObjectName("pushButton_Factorial");
        sizePolicy.setHeightForWidth(pushButton_Factorial->sizePolicy().hasHeightForWidth());
        pushButton_Factorial->setSizePolicy(sizePolicy);
        pushButton_Factorial->setFont(font4);
        pushButton_Factorial->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Factorial, 2, 5, 1, 1);

        pushButton_Deg = new QPushButton(PageScientific);
        pushButton_Deg->setObjectName("pushButton_Deg");
        sizePolicy.setHeightForWidth(pushButton_Deg->sizePolicy().hasHeightForWidth());
        pushButton_Deg->setSizePolicy(sizePolicy);
        pushButton_Deg->setFont(font4);
        pushButton_Deg->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_Deg, 6, 1, 1, 1);

        pushButton_4_ = new QPushButton(PageScientific);
        pushButton_4_->setObjectName("pushButton_4_");
        sizePolicy.setHeightForWidth(pushButton_4_->sizePolicy().hasHeightForWidth());
        pushButton_4_->setSizePolicy(sizePolicy);
        pushButton_4_->setFont(font4);
        pushButton_4_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_4_, 5, 2, 1, 1);

        pushButton_Comma = new QPushButton(PageScientific);
        pushButton_Comma->setObjectName("pushButton_Comma");
        sizePolicy.setHeightForWidth(pushButton_Comma->sizePolicy().hasHeightForWidth());
        pushButton_Comma->setSizePolicy(sizePolicy);
        pushButton_Comma->setFont(font4);
        pushButton_Comma->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_Comma, 7, 2, 1, 1);

        pushButton_Minus_ = new QPushButton(PageScientific);
        pushButton_Minus_->setObjectName("pushButton_Minus_");
        sizePolicy.setHeightForWidth(pushButton_Minus_->sizePolicy().hasHeightForWidth());
        pushButton_Minus_->setSizePolicy(sizePolicy);
        pushButton_Minus_->setFont(font4);
        pushButton_Minus_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_Minus_, 7, 1, 1, 1);

        pushButton_RightParen = new QPushButton(PageScientific);
        pushButton_RightParen->setObjectName("pushButton_RightParen");
        sizePolicy.setHeightForWidth(pushButton_RightParen->sizePolicy().hasHeightForWidth());
        pushButton_RightParen->setSizePolicy(sizePolicy);
        pushButton_RightParen->setFont(font4);
        pushButton_RightParen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_RightParen, 2, 4, 1, 1);

        pushButton_Add_ = new QPushButton(PageScientific);
        pushButton_Add_->setObjectName("pushButton_Add_");
        sizePolicy.setHeightForWidth(pushButton_Add_->sizePolicy().hasHeightForWidth());
        pushButton_Add_->setSizePolicy(sizePolicy);
        pushButton_Add_->setFont(font4);
        pushButton_Add_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Add_, 6, 6, 1, 1);

        pushButton_1_ = new QPushButton(PageScientific);
        pushButton_1_->setObjectName("pushButton_1_");
        sizePolicy.setHeightForWidth(pushButton_1_->sizePolicy().hasHeightForWidth());
        pushButton_1_->setSizePolicy(sizePolicy);
        pushButton_1_->setFont(font4);
        pushButton_1_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_1_, 6, 2, 1, 1);

        pushButton_Log = new QPushButton(PageScientific);
        pushButton_Log->setObjectName("pushButton_Log");
        sizePolicy.setHeightForWidth(pushButton_Log->sizePolicy().hasHeightForWidth());
        pushButton_Log->setSizePolicy(sizePolicy);
        pushButton_Log->setMinimumSize(QSize(30, 30));
        pushButton_Log->setFont(font4);
        pushButton_Log->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Log, 0, 2, 1, 1);

        pushButton_7_ = new QPushButton(PageScientific);
        pushButton_7_->setObjectName("pushButton_7_");
        sizePolicy.setHeightForWidth(pushButton_7_->sizePolicy().hasHeightForWidth());
        pushButton_7_->setSizePolicy(sizePolicy);
        pushButton_7_->setFont(font4);
        pushButton_7_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_7_, 4, 2, 1, 1);

        pushButton_3_ = new QPushButton(PageScientific);
        pushButton_3_->setObjectName("pushButton_3_");
        sizePolicy.setHeightForWidth(pushButton_3_->sizePolicy().hasHeightForWidth());
        pushButton_3_->setSizePolicy(sizePolicy);
        pushButton_3_->setFont(font4);
        pushButton_3_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_3_, 6, 5, 1, 1);

        pushButton_Multi_ = new QPushButton(PageScientific);
        pushButton_Multi_->setObjectName("pushButton_Multi_");
        sizePolicy.setHeightForWidth(pushButton_Multi_->sizePolicy().hasHeightForWidth());
        pushButton_Multi_->setSizePolicy(sizePolicy);
        pushButton_Multi_->setFont(font4);
        pushButton_Multi_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Multi_, 4, 6, 1, 1);

        pushButton_Sqrt_ = new QPushButton(PageScientific);
        pushButton_Sqrt_->setObjectName("pushButton_Sqrt_");
        sizePolicy.setHeightForWidth(pushButton_Sqrt_->sizePolicy().hasHeightForWidth());
        pushButton_Sqrt_->setSizePolicy(sizePolicy);
        pushButton_Sqrt_->setFont(font4);
        pushButton_Sqrt_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Sqrt_, 1, 1, 1, 1);

        pushButton_Pow = new QPushButton(PageScientific);
        pushButton_Pow->setObjectName("pushButton_Pow");
        sizePolicy.setHeightForWidth(pushButton_Pow->sizePolicy().hasHeightForWidth());
        pushButton_Pow->setSizePolicy(sizePolicy);
        pushButton_Pow->setFont(font4);
        pushButton_Pow->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Pow, 2, 1, 1, 1);

        pushButton_9_ = new QPushButton(PageScientific);
        pushButton_9_->setObjectName("pushButton_9_");
        sizePolicy.setHeightForWidth(pushButton_9_->sizePolicy().hasHeightForWidth());
        pushButton_9_->setSizePolicy(sizePolicy);
        pushButton_9_->setFont(font4);
        pushButton_9_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_9_, 4, 5, 1, 1);

        pushButton_PI = new QPushButton(PageScientific);
        pushButton_PI->setObjectName("pushButton_PI");
        sizePolicy.setHeightForWidth(pushButton_PI->sizePolicy().hasHeightForWidth());
        pushButton_PI->setSizePolicy(sizePolicy);
        pushButton_PI->setFont(font4);
        pushButton_PI->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_PI, 4, 1, 1, 1);

        pushButton_Divide_ = new QPushButton(PageScientific);
        pushButton_Divide_->setObjectName("pushButton_Divide_");
        sizePolicy.setHeightForWidth(pushButton_Divide_->sizePolicy().hasHeightForWidth());
        pushButton_Divide_->setSizePolicy(sizePolicy);
        pushButton_Divide_->setFont(font4);
        pushButton_Divide_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Divide_, 2, 6, 1, 1);

        pushButton_2_ = new QPushButton(PageScientific);
        pushButton_2_->setObjectName("pushButton_2_");
        sizePolicy.setHeightForWidth(pushButton_2_->sizePolicy().hasHeightForWidth());
        pushButton_2_->setSizePolicy(sizePolicy);
        pushButton_2_->setFont(font4);
        pushButton_2_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_2_, 6, 4, 1, 1);

        pushButton_Sub_ = new QPushButton(PageScientific);
        pushButton_Sub_->setObjectName("pushButton_Sub_");
        sizePolicy.setHeightForWidth(pushButton_Sub_->sizePolicy().hasHeightForWidth());
        pushButton_Sub_->setSizePolicy(sizePolicy);
        pushButton_Sub_->setFont(font4);
        pushButton_Sub_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Sub_, 5, 6, 1, 1);

        pushButton_Point_ = new QPushButton(PageScientific);
        pushButton_Point_->setObjectName("pushButton_Point_");
        sizePolicy.setHeightForWidth(pushButton_Point_->sizePolicy().hasHeightForWidth());
        pushButton_Point_->setSizePolicy(sizePolicy);
        pushButton_Point_->setFont(font4);
        pushButton_Point_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_Point_, 7, 5, 1, 1);

        pushButton_Reciprocal_ = new QPushButton(PageScientific);
        pushButton_Reciprocal_->setObjectName("pushButton_Reciprocal_");
        sizePolicy.setHeightForWidth(pushButton_Reciprocal_->sizePolicy().hasHeightForWidth());
        pushButton_Reciprocal_->setSizePolicy(sizePolicy);
        pushButton_Reciprocal_->setFont(font4);
        pushButton_Reciprocal_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Reciprocal_, 1, 2, 1, 1);

        pushButton_Abs = new QPushButton(PageScientific);
        pushButton_Abs->setObjectName("pushButton_Abs");
        sizePolicy.setHeightForWidth(pushButton_Abs->sizePolicy().hasHeightForWidth());
        pushButton_Abs->setSizePolicy(sizePolicy);
        pushButton_Abs->setFont(font4);
        pushButton_Abs->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Abs, 1, 4, 1, 1);

        pushButton_Mod_ = new QPushButton(PageScientific);
        pushButton_Mod_->setObjectName("pushButton_Mod_");
        sizePolicy.setHeightForWidth(pushButton_Mod_->sizePolicy().hasHeightForWidth());
        pushButton_Mod_->setSizePolicy(sizePolicy);
        pushButton_Mod_->setMinimumSize(QSize(30, 30));
        pushButton_Mod_->setFont(font4);
        pushButton_Mod_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Mod_, 1, 6, 1, 1);

        pushButton_Euler = new QPushButton(PageScientific);
        pushButton_Euler->setObjectName("pushButton_Euler");
        sizePolicy.setHeightForWidth(pushButton_Euler->sizePolicy().hasHeightForWidth());
        pushButton_Euler->setSizePolicy(sizePolicy);
        pushButton_Euler->setFont(font4);
        pushButton_Euler->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_Euler, 5, 1, 1, 1);

        pushButton_0_ = new QPushButton(PageScientific);
        pushButton_0_->setObjectName("pushButton_0_");
        sizePolicy.setHeightForWidth(pushButton_0_->sizePolicy().hasHeightForWidth());
        pushButton_0_->setSizePolicy(sizePolicy);
        pushButton_0_->setFont(font4);
        pushButton_0_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_0_, 7, 4, 1, 1);

        pushButton_5_ = new QPushButton(PageScientific);
        pushButton_5_->setObjectName("pushButton_5_");
        sizePolicy.setHeightForWidth(pushButton_5_->sizePolicy().hasHeightForWidth());
        pushButton_5_->setSizePolicy(sizePolicy);
        pushButton_5_->setFont(font4);
        pushButton_5_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_5_, 5, 4, 1, 1);

        pushButton_Square_ = new QPushButton(PageScientific);
        pushButton_Square_->setObjectName("pushButton_Square_");
        sizePolicy.setHeightForWidth(pushButton_Square_->sizePolicy().hasHeightForWidth());
        pushButton_Square_->setSizePolicy(sizePolicy);
        pushButton_Square_->setMinimumSize(QSize(30, 30));
        pushButton_Square_->setFont(font4);
        pushButton_Square_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Square_, 0, 1, 1, 1);

        pushButton_Clear_ = new QPushButton(PageScientific);
        pushButton_Clear_->setObjectName("pushButton_Clear_");
        sizePolicy.setHeightForWidth(pushButton_Clear_->sizePolicy().hasHeightForWidth());
        pushButton_Clear_->setSizePolicy(sizePolicy);
        pushButton_Clear_->setMinimumSize(QSize(30, 30));
        pushButton_Clear_->setFont(font4);
        pushButton_Clear_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Clear_, 0, 5, 1, 1);

        pushButton_Exe = new QPushButton(PageScientific);
        pushButton_Exe->setObjectName("pushButton_Exe");
        sizePolicy.setHeightForWidth(pushButton_Exe->sizePolicy().hasHeightForWidth());
        pushButton_Exe->setSizePolicy(sizePolicy);
        pushButton_Exe->setFont(font4);
        pushButton_Exe->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Exe, 1, 5, 1, 1);

        pushButton_Delet_ = new QPushButton(PageScientific);
        pushButton_Delet_->setObjectName("pushButton_Delet_");
        sizePolicy.setHeightForWidth(pushButton_Delet_->sizePolicy().hasHeightForWidth());
        pushButton_Delet_->setSizePolicy(sizePolicy);
        pushButton_Delet_->setMinimumSize(QSize(30, 30));
        pushButton_Delet_->setFont(font4);
        pushButton_Delet_->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Delet_, 0, 6, 1, 1);

        pushButton_8_ = new QPushButton(PageScientific);
        pushButton_8_->setObjectName("pushButton_8_");
        sizePolicy.setHeightForWidth(pushButton_8_->sizePolicy().hasHeightForWidth());
        pushButton_8_->setSizePolicy(sizePolicy);
        pushButton_8_->setFont(font4);
        pushButton_8_->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        Key_Back->addWidget(pushButton_8_, 4, 4, 1, 1);

        pushButton_Ln = new QPushButton(PageScientific);
        pushButton_Ln->setObjectName("pushButton_Ln");
        sizePolicy.setHeightForWidth(pushButton_Ln->sizePolicy().hasHeightForWidth());
        pushButton_Ln->setSizePolicy(sizePolicy);
        pushButton_Ln->setMinimumSize(QSize(30, 30));
        pushButton_Ln->setFont(font4);
        pushButton_Ln->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        Key_Back->addWidget(pushButton_Ln, 0, 4, 1, 1);


        verticalLayout_3->addLayout(Key_Back);

        KeyStack->addWidget(PageScientific);
        PageProgrammer = new QWidget();
        PageProgrammer->setObjectName("PageProgrammer");
        sizePolicy.setHeightForWidth(PageProgrammer->sizePolicy().hasHeightForWidth());
        PageProgrammer->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(PageProgrammer);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton___LeftParen = new QPushButton(PageProgrammer);
        pushButton___LeftParen->setObjectName("pushButton___LeftParen");
        sizePolicy.setHeightForWidth(pushButton___LeftParen->sizePolicy().hasHeightForWidth());
        pushButton___LeftParen->setSizePolicy(sizePolicy);
        pushButton___LeftParen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___LeftParen, 0, 0, 1, 1);

        pushButton___RightParen = new QPushButton(PageProgrammer);
        pushButton___RightParen->setObjectName("pushButton___RightParen");
        sizePolicy.setHeightForWidth(pushButton___RightParen->sizePolicy().hasHeightForWidth());
        pushButton___RightParen->setSizePolicy(sizePolicy);
        pushButton___RightParen->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___RightParen, 0, 1, 1, 1);

        pushButton___Clear = new QPushButton(PageProgrammer);
        pushButton___Clear->setObjectName("pushButton___Clear");
        sizePolicy.setHeightForWidth(pushButton___Clear->sizePolicy().hasHeightForWidth());
        pushButton___Clear->setSizePolicy(sizePolicy);
        pushButton___Clear->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___Clear, 0, 2, 1, 1);

        pushButton___BackSpace = new QPushButton(PageProgrammer);
        pushButton___BackSpace->setObjectName("pushButton___BackSpace");
        sizePolicy.setHeightForWidth(pushButton___BackSpace->sizePolicy().hasHeightForWidth());
        pushButton___BackSpace->setSizePolicy(sizePolicy);
        pushButton___BackSpace->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___BackSpace, 0, 3, 1, 1);

        pushButton_AND = new QPushButton(PageProgrammer);
        pushButton_AND->setObjectName("pushButton_AND");
        sizePolicy.setHeightForWidth(pushButton_AND->sizePolicy().hasHeightForWidth());
        pushButton_AND->setSizePolicy(sizePolicy);
        pushButton_AND->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton_AND, 1, 0, 1, 1);

        pushButton_OR = new QPushButton(PageProgrammer);
        pushButton_OR->setObjectName("pushButton_OR");
        sizePolicy.setHeightForWidth(pushButton_OR->sizePolicy().hasHeightForWidth());
        pushButton_OR->setSizePolicy(sizePolicy);
        pushButton_OR->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton_OR, 1, 1, 1, 1);

        pushButton_XOR = new QPushButton(PageProgrammer);
        pushButton_XOR->setObjectName("pushButton_XOR");
        sizePolicy.setHeightForWidth(pushButton_XOR->sizePolicy().hasHeightForWidth());
        pushButton_XOR->setSizePolicy(sizePolicy);
        pushButton_XOR->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton_XOR, 1, 2, 1, 1);

        pushButton___Divide = new QPushButton(PageProgrammer);
        pushButton___Divide->setObjectName("pushButton___Divide");
        sizePolicy.setHeightForWidth(pushButton___Divide->sizePolicy().hasHeightForWidth());
        pushButton___Divide->setSizePolicy(sizePolicy);
        pushButton___Divide->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___Divide, 1, 3, 1, 1);

        pushButton___7 = new QPushButton(PageProgrammer);
        pushButton___7->setObjectName("pushButton___7");
        sizePolicy.setHeightForWidth(pushButton___7->sizePolicy().hasHeightForWidth());
        pushButton___7->setSizePolicy(sizePolicy);
        pushButton___7->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___7, 2, 0, 1, 1);

        pushButton___8 = new QPushButton(PageProgrammer);
        pushButton___8->setObjectName("pushButton___8");
        sizePolicy.setHeightForWidth(pushButton___8->sizePolicy().hasHeightForWidth());
        pushButton___8->setSizePolicy(sizePolicy);
        pushButton___8->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___8, 2, 1, 1, 1);

        pushButton___9 = new QPushButton(PageProgrammer);
        pushButton___9->setObjectName("pushButton___9");
        sizePolicy.setHeightForWidth(pushButton___9->sizePolicy().hasHeightForWidth());
        pushButton___9->setSizePolicy(sizePolicy);
        pushButton___9->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___9, 2, 2, 1, 1);

        pushButton___Multi = new QPushButton(PageProgrammer);
        pushButton___Multi->setObjectName("pushButton___Multi");
        sizePolicy.setHeightForWidth(pushButton___Multi->sizePolicy().hasHeightForWidth());
        pushButton___Multi->setSizePolicy(sizePolicy);
        pushButton___Multi->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___Multi, 2, 3, 1, 1);

        pushButton___4 = new QPushButton(PageProgrammer);
        pushButton___4->setObjectName("pushButton___4");
        sizePolicy.setHeightForWidth(pushButton___4->sizePolicy().hasHeightForWidth());
        pushButton___4->setSizePolicy(sizePolicy);
        pushButton___4->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___4, 3, 0, 1, 1);

        pushButton___5 = new QPushButton(PageProgrammer);
        pushButton___5->setObjectName("pushButton___5");
        sizePolicy.setHeightForWidth(pushButton___5->sizePolicy().hasHeightForWidth());
        pushButton___5->setSizePolicy(sizePolicy);
        pushButton___5->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___5, 3, 1, 1, 1);

        pushButton___6 = new QPushButton(PageProgrammer);
        pushButton___6->setObjectName("pushButton___6");
        sizePolicy.setHeightForWidth(pushButton___6->sizePolicy().hasHeightForWidth());
        pushButton___6->setSizePolicy(sizePolicy);
        pushButton___6->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___6, 3, 2, 1, 1);

        pushButton___Sub = new QPushButton(PageProgrammer);
        pushButton___Sub->setObjectName("pushButton___Sub");
        sizePolicy.setHeightForWidth(pushButton___Sub->sizePolicy().hasHeightForWidth());
        pushButton___Sub->setSizePolicy(sizePolicy);
        pushButton___Sub->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___Sub, 3, 3, 1, 1);

        pushButton___1 = new QPushButton(PageProgrammer);
        pushButton___1->setObjectName("pushButton___1");
        sizePolicy.setHeightForWidth(pushButton___1->sizePolicy().hasHeightForWidth());
        pushButton___1->setSizePolicy(sizePolicy);
        pushButton___1->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___1, 4, 0, 1, 1);

        pushButton___2 = new QPushButton(PageProgrammer);
        pushButton___2->setObjectName("pushButton___2");
        sizePolicy.setHeightForWidth(pushButton___2->sizePolicy().hasHeightForWidth());
        pushButton___2->setSizePolicy(sizePolicy);
        pushButton___2->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___2, 4, 1, 1, 1);

        pushButton___3 = new QPushButton(PageProgrammer);
        pushButton___3->setObjectName("pushButton___3");
        sizePolicy.setHeightForWidth(pushButton___3->sizePolicy().hasHeightForWidth());
        pushButton___3->setSizePolicy(sizePolicy);
        pushButton___3->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___3, 4, 2, 1, 1);

        pushButton___Add = new QPushButton(PageProgrammer);
        pushButton___Add->setObjectName("pushButton___Add");
        sizePolicy.setHeightForWidth(pushButton___Add->sizePolicy().hasHeightForWidth());
        pushButton___Add->setSizePolicy(sizePolicy);
        pushButton___Add->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #444444;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #505050;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #666666;\n"
"}"));

        gridLayout->addWidget(pushButton___Add, 4, 3, 1, 1);

        pushButton___Minus = new QPushButton(PageProgrammer);
        pushButton___Minus->setObjectName("pushButton___Minus");
        sizePolicy.setHeightForWidth(pushButton___Minus->sizePolicy().hasHeightForWidth());
        pushButton___Minus->setSizePolicy(sizePolicy);
        pushButton___Minus->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___Minus, 5, 0, 1, 1);

        pushButton___0 = new QPushButton(PageProgrammer);
        pushButton___0->setObjectName("pushButton___0");
        sizePolicy.setHeightForWidth(pushButton___0->sizePolicy().hasHeightForWidth());
        pushButton___0->setSizePolicy(sizePolicy);
        pushButton___0->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___0, 5, 1, 1, 1);

        pushButton___Point = new QPushButton(PageProgrammer);
        pushButton___Point->setObjectName("pushButton___Point");
        sizePolicy.setHeightForWidth(pushButton___Point->sizePolicy().hasHeightForWidth());
        pushButton___Point->setSizePolicy(sizePolicy);
        pushButton___Point->setStyleSheet(QString::fromUtf8(" QPushButton\n"
"{\n"
"        background-color:#52565c;\n"
"        color:#ffffff;\n"
"        border:none;\n"
"        border-radius:4px;\n"
"        min-width:30px;\n"
"        min-height:30px;\n"
"        font-size:20px;\n"
" }\n"
"QPushButton:hover\n"
"{\n"
"	 background-color:#5d6269;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:#6a7078;\n"
"}"));

        gridLayout->addWidget(pushButton___Point, 5, 2, 1, 1);

        pushButton___Equal = new QPushButton(PageProgrammer);
        pushButton___Equal->setObjectName("pushButton___Equal");
        sizePolicy.setHeightForWidth(pushButton___Equal->sizePolicy().hasHeightForWidth());
        pushButton___Equal->setSizePolicy(sizePolicy);
        pushButton___Equal->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color: #f0f0f0;\n"
"    color: #333333;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 30px;\n"
"    min-height: 30px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #e5e5e5;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #d5d5d5;\n"
"}"));

        gridLayout->addWidget(pushButton___Equal, 5, 3, 1, 1);

        KeyStack->addWidget(PageProgrammer);

        verticalLayout->addWidget(KeyStack);


        verticalLayout_2->addWidget(calculatorBody);

        QWidget::setTabOrder(pushButton1, pushButton2);
        QWidget::setTabOrder(pushButton2, pushButton3);
        QWidget::setTabOrder(pushButton3, pushButton5);
        QWidget::setTabOrder(pushButton5, pushButton6);
        QWidget::setTabOrder(pushButton6, pushButton0);
        QWidget::setTabOrder(pushButton0, pushButton_Sub);
        QWidget::setTabOrder(pushButton_Sub, pushButton_Add);
        QWidget::setTabOrder(pushButton_Add, pushButton_Equal);
        QWidget::setTabOrder(pushButton_Equal, pushButton_Dot);

        retranslateUi(CalculatorUIClass);

        KeyStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CalculatorUIClass);
    } // setupUi

    void retranslateUi(QWidget *CalculatorUIClass)
    {
        CalculatorUIClass->setWindowTitle(QCoreApplication::translate("CalculatorUIClass", "CalculatorUI", nullptr));
        Name->setText(QCoreApplication::translate("CalculatorUIClass", "Calculator", nullptr));
        InputLine->setText(QString());
        pushButton0->setText(QCoreApplication::translate("CalculatorUIClass", "0", nullptr));
        pushButton7->setText(QCoreApplication::translate("CalculatorUIClass", "7", nullptr));
        pushButton_Dot->setText(QCoreApplication::translate("CalculatorUIClass", ".", nullptr));
        pushButton9->setText(QCoreApplication::translate("CalculatorUIClass", "9", nullptr));
        pushButton6->setText(QCoreApplication::translate("CalculatorUIClass", "6", nullptr));
        pushButton_Minus->setText(QCoreApplication::translate("CalculatorUIClass", "+/-", nullptr));
        pushButton_Equal->setText(QCoreApplication::translate("CalculatorUIClass", "=", nullptr));
        pushButton_Sqrt->setText(QCoreApplication::translate("CalculatorUIClass", "\342\210\232", nullptr));
        pushButton5->setText(QCoreApplication::translate("CalculatorUIClass", "5", nullptr));
        pushButton8->setText(QCoreApplication::translate("CalculatorUIClass", "8", nullptr));
        pushButton_Multi->setText(QCoreApplication::translate("CalculatorUIClass", "\342\205\271", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("CalculatorUIClass", "+", nullptr));
        pushButton_BackSpace->setText(QCoreApplication::translate("CalculatorUIClass", "\342\214\253", nullptr));
        pushButton_ClearAll->setText(QCoreApplication::translate("CalculatorUIClass", "C", nullptr));
        pushButton3->setText(QCoreApplication::translate("CalculatorUIClass", "3", nullptr));
        pushButton_Mod->setText(QCoreApplication::translate("CalculatorUIClass", "%", nullptr));
        pushButton_ClearCurrent->setText(QCoreApplication::translate("CalculatorUIClass", "CE", nullptr));
        pushButton2->setText(QCoreApplication::translate("CalculatorUIClass", "2", nullptr));
        pushButton4->setText(QCoreApplication::translate("CalculatorUIClass", "4", nullptr));
        pushButton1->setText(QCoreApplication::translate("CalculatorUIClass", "1", nullptr));
        pushButton_Divide->setText(QCoreApplication::translate("CalculatorUIClass", "\303\267", nullptr));
        pushButton_Square->setText(QCoreApplication::translate("CalculatorUIClass", "x\302\262", nullptr));
        pushButton_Reciprocal->setText(QCoreApplication::translate("CalculatorUIClass", "1/x", nullptr));
        pushButton_Sub->setText(QCoreApplication::translate("CalculatorUIClass", "-", nullptr));
        pushButton_triangle_function->setText(QCoreApplication::translate("CalculatorUIClass", "\342\210\240 \344\270\211\350\247\222 \342\217\267", nullptr));
        pushButton_more_function->setText(QCoreApplication::translate("CalculatorUIClass", "\360\235\222\207(\360\235\222\231) \345\207\275\346\225\260 \342\217\267", nullptr));
        pushButton_rad_and_deg->setText(QCoreApplication::translate("CalculatorUIClass", "Rad", nullptr));
        pushButton_LeftParen->setText(QCoreApplication::translate("CalculatorUIClass", "(", nullptr));
        pushButton_Equal_->setText(QCoreApplication::translate("CalculatorUIClass", "=", nullptr));
        pushButton_6_->setText(QCoreApplication::translate("CalculatorUIClass", "6", nullptr));
        pushButton_Factorial->setText(QCoreApplication::translate("CalculatorUIClass", "n!", nullptr));
        pushButton_Deg->setText(QCoreApplication::translate("CalculatorUIClass", "\302\260", nullptr));
        pushButton_4_->setText(QCoreApplication::translate("CalculatorUIClass", "4", nullptr));
        pushButton_Comma->setText(QCoreApplication::translate("CalculatorUIClass", ",", nullptr));
        pushButton_Minus_->setText(QCoreApplication::translate("CalculatorUIClass", "+/-", nullptr));
        pushButton_RightParen->setText(QCoreApplication::translate("CalculatorUIClass", ")", nullptr));
        pushButton_Add_->setText(QCoreApplication::translate("CalculatorUIClass", "+", nullptr));
        pushButton_1_->setText(QCoreApplication::translate("CalculatorUIClass", "1", nullptr));
        pushButton_Log->setText(QCoreApplication::translate("CalculatorUIClass", "log", nullptr));
        pushButton_7_->setText(QCoreApplication::translate("CalculatorUIClass", "7", nullptr));
        pushButton_3_->setText(QCoreApplication::translate("CalculatorUIClass", "3", nullptr));
        pushButton_Multi_->setText(QCoreApplication::translate("CalculatorUIClass", "\342\205\271", nullptr));
        pushButton_Sqrt_->setText(QCoreApplication::translate("CalculatorUIClass", "\342\210\232", nullptr));
        pushButton_Pow->setText(QCoreApplication::translate("CalculatorUIClass", " x\312\270", nullptr));
        pushButton_9_->setText(QCoreApplication::translate("CalculatorUIClass", "9", nullptr));
        pushButton_PI->setText(QCoreApplication::translate("CalculatorUIClass", "\317\200", nullptr));
        pushButton_Divide_->setText(QCoreApplication::translate("CalculatorUIClass", "\303\267", nullptr));
        pushButton_2_->setText(QCoreApplication::translate("CalculatorUIClass", "2", nullptr));
        pushButton_Sub_->setText(QCoreApplication::translate("CalculatorUIClass", "-", nullptr));
        pushButton_Point_->setText(QCoreApplication::translate("CalculatorUIClass", ".", nullptr));
        pushButton_Reciprocal_->setText(QCoreApplication::translate("CalculatorUIClass", "1/x", nullptr));
        pushButton_Abs->setText(QCoreApplication::translate("CalculatorUIClass", "|x|", nullptr));
        pushButton_Mod_->setText(QCoreApplication::translate("CalculatorUIClass", "%", nullptr));
        pushButton_Euler->setText(QCoreApplication::translate("CalculatorUIClass", "e", nullptr));
        pushButton_0_->setText(QCoreApplication::translate("CalculatorUIClass", "0", nullptr));
        pushButton_5_->setText(QCoreApplication::translate("CalculatorUIClass", "5", nullptr));
        pushButton_Square_->setText(QCoreApplication::translate("CalculatorUIClass", "x\302\262", nullptr));
        pushButton_Clear_->setText(QCoreApplication::translate("CalculatorUIClass", "C", nullptr));
        pushButton_Exe->setText(QCoreApplication::translate("CalculatorUIClass", "e\313\243", nullptr));
        pushButton_Delet_->setText(QCoreApplication::translate("CalculatorUIClass", "\342\214\253", nullptr));
        pushButton_8_->setText(QCoreApplication::translate("CalculatorUIClass", "8", nullptr));
        pushButton_Ln->setText(QCoreApplication::translate("CalculatorUIClass", "ln", nullptr));
        pushButton___LeftParen->setText(QCoreApplication::translate("CalculatorUIClass", "(", nullptr));
        pushButton___RightParen->setText(QCoreApplication::translate("CalculatorUIClass", ")", nullptr));
        pushButton___Clear->setText(QCoreApplication::translate("CalculatorUIClass", "C", nullptr));
        pushButton___BackSpace->setText(QCoreApplication::translate("CalculatorUIClass", "\342\214\253", nullptr));
        pushButton_AND->setText(QCoreApplication::translate("CalculatorUIClass", "&&", nullptr));
        pushButton_OR->setText(QCoreApplication::translate("CalculatorUIClass", "|", nullptr));
        pushButton_XOR->setText(QCoreApplication::translate("CalculatorUIClass", "~", nullptr));
        pushButton___Divide->setText(QCoreApplication::translate("CalculatorUIClass", "\303\267", nullptr));
        pushButton___7->setText(QCoreApplication::translate("CalculatorUIClass", "7", nullptr));
        pushButton___8->setText(QCoreApplication::translate("CalculatorUIClass", "8", nullptr));
        pushButton___9->setText(QCoreApplication::translate("CalculatorUIClass", "9", nullptr));
        pushButton___Multi->setText(QCoreApplication::translate("CalculatorUIClass", "\342\205\271", nullptr));
        pushButton___4->setText(QCoreApplication::translate("CalculatorUIClass", "4", nullptr));
        pushButton___5->setText(QCoreApplication::translate("CalculatorUIClass", "5", nullptr));
        pushButton___6->setText(QCoreApplication::translate("CalculatorUIClass", "6", nullptr));
        pushButton___Sub->setText(QCoreApplication::translate("CalculatorUIClass", "-", nullptr));
        pushButton___1->setText(QCoreApplication::translate("CalculatorUIClass", "1", nullptr));
        pushButton___2->setText(QCoreApplication::translate("CalculatorUIClass", "2", nullptr));
        pushButton___3->setText(QCoreApplication::translate("CalculatorUIClass", "3", nullptr));
        pushButton___Add->setText(QCoreApplication::translate("CalculatorUIClass", "+", nullptr));
        pushButton___Minus->setText(QCoreApplication::translate("CalculatorUIClass", "+/-", nullptr));
        pushButton___0->setText(QCoreApplication::translate("CalculatorUIClass", "0", nullptr));
        pushButton___Point->setText(QCoreApplication::translate("CalculatorUIClass", ".", nullptr));
        pushButton___Equal->setText(QCoreApplication::translate("CalculatorUIClass", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorUIClass: public Ui_CalculatorUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
