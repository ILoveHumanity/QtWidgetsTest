#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura
{
protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *Painter) = 0;
public:
    virtual ~Figura() = default; // Виртуальный деструктор
    Figura() = default;
    Figura(int X, int Y, int Halflen); // Конструктор
    void move(float Alpha, QPainter *Painter); // Метод перемещения: вычисляет новые координаты по углу поворота и вызывает переопределённый метод draw() для отрисовки.
};

class MyLine : public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    ~MyLine() = default;
    MyLine() = default;
    MyLine(int x, int y, int halflen);
};

class MyRect : public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    ~MyRect() = default;
    MyRect() = default;
    MyRect(int x, int y, int halflen);
};

#endif // FIGURA_H
