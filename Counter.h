#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>
#include <QtWidgets>

class Counter : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent = nullptr);
    ~Counter() = default;
signals:
    void tick_signal();
public slots:
    void add_one();
};

class Win: public QWidget
{
    Q_OBJECT
protected:
    QTextCodec *codec;
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win(QWidget *parent = nullptr);
    ~Win() = default;
};

#endif // COUNTER_H
