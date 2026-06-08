#ifndef AREA_H
#define AREA_H

#include "Figura.h"
#include <QWidget>
#include <QPaintEvent>
#include <QTimerEvent>
#include <QShowEvent>
#include <QHideEvent>

class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
public:
    Area(QWidget *parent = nullptr);
    ~Area();
    MyLine *myline; // фигура "линия"
    MyRect *myrect; // фигура "прямоугольник"
protected:
    //обработчики событий
    void paintEvent(QPaintEvent *event); // отрисовка содержимого виджета
    void timerEvent(QTimerEvent *event); // обработка срабатывания таймера анимации
    void showEvent(QShowEvent *event); // запуск таймера при отображении виджета
    void hideEvent(QHideEvent *event); // остановка таймера при скрытии виджета
};

#endif // AREA_H
