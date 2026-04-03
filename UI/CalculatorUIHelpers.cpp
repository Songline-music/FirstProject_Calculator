#include "UI/CalculatorUI.hpp"

#include <QTextCursor>
#include <QTextBlockFormat>
#include <QPainter>
#include <QPlainTextEdit>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextBrowser>
#include <QAbstractButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>

// 获取等号后文本
QString ExtractResultText(const std::string& content)
{
    const QString all = QString::fromStdString(content);
    const QStringList lines = all.split('\n', Qt::SkipEmptyParts);

    for (const QString& rawLine : lines)
    {
        const QString line = rawLine.trimmed();
        const int pos = line.lastIndexOf('=');
        if (pos != -1)
        {
            return line.mid(pos + 1).trimmed();
        }
    }

    return all.trimmed();
}

// 显示文本提取
QString ExtractDisplayText(const std::string& content)
{
    const QString all = QString::fromStdString(content);
    const QStringList lines = all.split('\n', Qt::SkipEmptyParts);

    if (lines.isEmpty()) return all.trimmed();

    if (lines.size() >= 2)
    {
        return lines.back().trimmed();
    }

    return ExtractResultText(content);
}

// 获取按键文本
QString GetButtonInput(QPushButton* button)
{
    if (!button)
    {
        return "";
    }

    QVariant value = button->property("input");
    return value.isValid() ? value.toString() : button->text();
}

// 把任意图标染成指定颜色（用于跨机器统一白色）
QIcon TintIcon(const QIcon& src, const QSize& size, const QColor& color)
{
    QPixmap pm = src.pixmap(size);
    if (pm.isNull()) return src;

    QPixmap out(pm.size());
    out.fill(Qt::transparent);

    QPainter p(&out);
    p.drawPixmap(0, 0, pm);
    p.setCompositionMode(QPainter::CompositionMode_SourceIn);
    p.fillRect(out.rect(), color);
    p.end();

    return QIcon(out);
}

// 边缘检测
Qt::Edges HitTestEdges(const QRect& rc, const QPoint& p, int m)
{
    Qt::Edges e{};
    if (p.x() <= rc.left() + m)  e |= Qt::LeftEdge;
    if (p.x() >= rc.right() - m) e |= Qt::RightEdge;
    if (p.y() <= rc.top() + m)   e |= Qt::TopEdge;
    if (p.y() >= rc.bottom() - m)e |= Qt::BottomEdge;
    return e;
}

// 根据边缘返回对应的鼠标指针形状
Qt::CursorShape CursorFromEdges(Qt::Edges e)
{
    if ((e & Qt::TopEdge) && (e & Qt::LeftEdge))   return Qt::SizeFDiagCursor;
    if ((e & Qt::BottomEdge) && (e & Qt::RightEdge)) return Qt::SizeFDiagCursor;
    if ((e & Qt::TopEdge) && (e & Qt::RightEdge))  return Qt::SizeBDiagCursor;
    if ((e & Qt::BottomEdge) && (e & Qt::LeftEdge))return Qt::SizeBDiagCursor;
    if ((e & Qt::LeftEdge) || (e & Qt::RightEdge)) return Qt::SizeHorCursor;
    if ((e & Qt::TopEdge) || (e & Qt::BottomEdge)) return Qt::SizeVerCursor;
    return Qt::ArrowCursor;
}

// 设置文本浏览器行距
void ApplyReadableSpacing(QTextBrowser* browser)
{
    if (!browser) return;

    QTextCursor c(browser->document());
    c.select(QTextCursor::Document);

    QTextBlockFormat fmt;
    fmt.setLineHeight(175, QTextBlockFormat::ProportionalHeight);
    fmt.setTopMargin(2);
    fmt.setBottomMargin(2);

    c.mergeBlockFormat(fmt);
}

// 文本规范化：统一 tab、全角空格，去除首尾空白
QString NormalizeEggText(const std::string& egg)
{
    QString s = QString::fromStdString(egg);
    s.replace('\t', "    ");
    s.replace(QString::fromUtf8("　"), " ");
    return s.trimmed();
}

// 显示彩蛋弹窗
void ShowEggPopup(QWidget* parent, const std::string& egg)
{
    auto* dlg = new QDialog(parent);
    dlg->setWindowTitle("Egg");
    dlg->setModal(true);
    dlg->resize(900, 680);
    dlg->setStyleSheet("QDialog{background:#1f1f1f; color:#e8e8e8;}");

    auto* root = new QVBoxLayout(dlg);
    root->setContentsMargins(12, 12, 12, 12);

    auto* view = new QPlainTextEdit(dlg);
    view->setReadOnly(true);
    view->setLineWrapMode(QPlainTextEdit::NoWrap);
    view->setPlainText(NormalizeEggText(egg));
    view->setStyleSheet(
        "QPlainTextEdit{background:#242424; color:#e8e8e8; border:1px solid #3a3a3a;}"
    );

    QFont mono("Cascadia Mono");
    mono.setStyleHint(QFont::Monospace);
    mono.setFixedPitch(true);
    mono.setPointSize(22);
    view->setFont(mono);

    auto* ok = new QPushButton("确定", dlg);
    ok->setMinimumSize(120, 44);
    ok->setStyleSheet("QPushButton{font-size:18px;}");
    QObject::connect(ok, &QPushButton::clicked, dlg, &QDialog::accept);

    root->addWidget(view, 1);
    root->addWidget(ok, 0, Qt::AlignRight);

    dlg->exec();
    dlg->deleteLater();
}

// 判断控件或其祖先是否为交互式输入控件（按钮、文本框、下拉框等）
bool IsInteractiveWidgetOrAncestor(QWidget* w)
{
    while (w)
    {
        if (qobject_cast<QAbstractButton*>(w) ||
            qobject_cast<QLineEdit*>(w) ||
            qobject_cast<QComboBox*>(w) ||
            qobject_cast<QSpinBox*>(w))
        {
            return true;
        }
        w = w->parentWidget();
    }
    return false;
}