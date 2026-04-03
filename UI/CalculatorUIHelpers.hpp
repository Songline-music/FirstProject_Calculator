#pragma once

#include "UI/CalculatorUI.hpp"
#include <string>
#include <QString>
#include <QIcon>
#include <QRect>
#include <QPoint>
#include <Qt>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QAbstractButton>

class QPushButton;
class QTextBrowser;
class QWidget;

QString ExtractResultText(const std::string& content);
QString ExtractDisplayText(const std::string& content);
QString GetButtonInput(QPushButton* button);

QIcon TintIcon(const QIcon& src, const QSize& size, const QColor& color);

Qt::Edges HitTestEdges(const QRect& rc, const QPoint& p, int m);
Qt::CursorShape CursorFromEdges(Qt::Edges e);

void ApplyReadableSpacing(QTextBrowser* browser);
QString NormalizeEggText(const std::string& egg);
void ShowEggPopup(QWidget* parent, const std::string& egg);

bool IsInteractiveWidgetOrAncestor(QWidget* w);