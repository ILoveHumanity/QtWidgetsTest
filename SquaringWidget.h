#ifndef SQUARINGWIDGET_H
#define SQUARINGWIDGET_H


//#include <QWidget>
//#include <QLabel>
//#include <QLineEdit>
//#include <QPushButton>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QMessageBox>
//#include <QValidator>

#include <QtWidgets>
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
public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
};

class StrValidator : public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos)const
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
};
#endif // SQUARINGWIDGET_H
