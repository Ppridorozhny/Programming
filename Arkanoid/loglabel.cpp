#include "loglabel.h"
#include <QPainter>
#include <QDebug>

LogLabel::LogLabel(QWidget *parent)
    : QWidget(parent)
{
    bounded = false;
}

void LogLabel::setText(const QString &text)
{
    bounded = false;
    this->text = text;
}

void LogLabel::paintEvent(QPaintEvent *)
{
    QPainter painter (this);

    if (bounded) {
        painter.drawText (rect (), text);

        return;
    }

    QRect bRect = painter.boundingRect(
                QRect (x (), y(), width (), height ()),
                0,
                text);

    setGeometry(bRect);
    painter.drawText (bRect, 0, text);
    bounded = true;
}
