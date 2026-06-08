#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>
#include <QObject>
#include <QTextCodec>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Counter : public QLineEdit
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
    Counter(const QString & contents, QWidget *parent = nullptr); // конструктор
    ~Counter() = default; // деструктор

signals:
    void tick_signal(); // сигнал, генерируемый при достижении значения, кратного 5

public slots:
    void add_one(); // слот увеличения значения на 1 с проверкой условия
};


class Win: public QWidget
{
    Q_OBJECT
protected:
    QTextCodec *codec; // кодек для русификации интерфейса (UTF-8)
    QLabel *label1, *label2; // надписи для пояснения полей ввода
    Counter *edit1, *edit2; // изменяемые поля: счёт по 1 и счёт по 5
    QPushButton *calcbutton; // кнопка +1
    QPushButton *exitbutton; // кнопка выхода
    bool isOk; // флаг состояния инициализации: отслеживает успешность создания виджетов

public:
    Win(QWidget *parent = nullptr); // конструктор
    ~Win() = default; // деструктор
};

#endif // COUNTER_H
