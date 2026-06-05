#ifndef AREA_H
#define AREA_H

#include "Figura.h"
#include <QtWidgets>

class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
public:
    Area(QWidget *parent = nullptr);
    ~Area();
    MyLine *myline;
    MyRect *myrect;
protected:
    //обработчики событий
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
};

#endif // AREA_H
