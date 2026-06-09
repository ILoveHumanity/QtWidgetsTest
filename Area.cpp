#include "Area.h"
#include "qglobal.h"
#include "QTextCodec"

Area::Area(QWidget *parent) : QWidget(parent)
{
    setFixedSize(QSize(300, 200)); // Окно фиксированного размера
    myline = MyLine(80, 100, 50);
    myrect = MyRect(220, 100, 50);
    alpha = 0; // угол поворота 0
}

void Area::showEvent(QShowEvent *)
{
    myTimer = startTimer(50); // создать таймер
}

void Area::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline.move(alpha, &painter);
    myrect.move(alpha*(-0.5), &painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event && event->timerId() == myTimer) { // если наш таймер
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
    else {
        QWidget::timerEvent(event); // иначе передать для стандартной обработки
    }
}

void Area::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event);
    killTimer(myTimer); // уничтожить таймер
}
