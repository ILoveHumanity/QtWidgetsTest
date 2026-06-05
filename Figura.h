#ifndef FIGURA_H
#define FIGURA_H

#include <QtWidgets>

class Figura
{
protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *Painter) = 0;
public:
    virtual ~Figura() = default;
    Figura(int X, int Y, int Halflen);
    void move(float Alpha, QPainter *Painter);
};

class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    ~MyLine() = default;
    MyLine(int x, int y, int halflen);
};

class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    ~MyRect() = default;
    MyRect(int x, int y, int halflen);
};

#endif // FIGURA_H
