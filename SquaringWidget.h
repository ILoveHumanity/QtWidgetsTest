#ifndef SQUARINGWIDGET_H
#define SQUARINGWIDGET_H


#include <QWidget>
#include <QObject>
#include <QTextCodec>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

//#include <QtWidgets>
class SquaringWidget : public QWidget //
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
    SquaringWidget(QWidget *parent = nullptr); // конструктор
    ~SquaringWidget() = default; // деструктор
protected:
    QTextCodec *codec;
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *resetButton; // кнопка Сброса
    QPushButton *exitButton; // кнопка Выход
    bool isOk; // Состояние (ок, не ок)

public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
};

class StrValidator : public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent);
    virtual State validate(QString &str,int &pos) const;
    bool getState();
};
#endif // SQUARINGWIDGET_H
