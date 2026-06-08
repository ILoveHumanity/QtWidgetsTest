#include "Area.h"
#include "qglobal.h"
#include "QTextCodec"

Area::Area(QWidget *parent) : QWidget(parent)
{
    setFixedSize(QSize(300, 200)); // Окно фиксированного размера
    myline = new MyLine(80, 100, 50);
    myrect = new MyRect(220, 100, 50);
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
    if (myline) {
        myline->move(alpha, &painter);
    }
    if (myrect) {
        myrect->move(alpha*(-0.5), &painter);
    }
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

Area::~Area()
{
    if (myline) {
        delete myline;
        myline = nullptr;
    }
    if (myrect) {
        delete myrect;
        myrect = nullptr;
    }
}
