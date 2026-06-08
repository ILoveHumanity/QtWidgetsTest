#include "Counter.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

Counter::Counter(const QString & contents, QWidget *parent) : QLineEdit(contents, parent) {}

void Counter::add_one()
{
    QString str = text(); // получаем текущее значение из поля ввода
    int r = str.toInt(); // преобразуем строку в целое число
    r++; // увеличиваем значение
    if (r != 0 && r % 5 == 0) { // проверяем условие: значение кратно 5 и не ноль
        emit tick_signal(); // генерируем сигнал для второго счётчика
    }
    str.setNum(r); // преобразуем результат обратно в строку
    setText(str); // обновляем отображаемое значение в поле ввода
}


Win::Win(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8"); // кодек для русификации интерфейса (UTF-8)
    setWindowTitle(codec->toUnicode("Счетчик")); // устанавливаем заголовок окна

    isOk = true;

    // Создаём текст для первого счётчика
    label1 = new QLabel(codec->toUnicode("Cчет по 1"), this);
    if (!label1 && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании текста 1."));
    }

    // Создаём текст для второго счётчика
    label2 = new QLabel(codec->toUnicode("Cчет по 5"), this);
    if (!label2 && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании текста 2."));
    }

    // Создаём первый счётчик (по 1)
    edit1 = new Counter("0", this);
    if (edit1) {
        edit1->setReadOnly(true); // Доступ только для чтения
    } else if (isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании счётчика 1."));
    }

    // Создаём второй счётчик (по 5 через сигнал)
    edit2 = new Counter("0", this);
    if (edit2) {
        edit2->setReadOnly(true); // Доступ только для чтения
    } else if (isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании счётчика 2."));
    }

    // Создаём кнопку +1
    calcbutton = new QPushButton("+1", this);
    if (!calcbutton && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании кнопки +1."));
    }

    // Создаём кнопку выхода
    exitbutton = new QPushButton(codec->toUnicode("Выход"), this);
    if (!exitbutton && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании кнопки выхода."));
    }

    // Если все виджеты созданы успешно — выполняем компоновку и подключение сигналов
    if (isOk) {
        // Вертикальная группа, объединяющая все горизонтальные группы
        QVBoxLayout *layout4 = new QVBoxLayout(this);
        if (layout4) {
            // Горизонтальная группа для меток
            QHBoxLayout *layout1 = new QHBoxLayout();
            if (layout1) {
                layout1->addWidget(label1);
                layout1->addWidget(label2);
            } else if (isOk) {
                isOk = false;
                setWindowTitle(codec->toUnicode("Ошибка при создании layout1."));
            }

            // Горизонтальная группа для полей ввода
            QHBoxLayout *layout2 = new QHBoxLayout();
            if (layout2) {
                layout2->addWidget(edit1);
                layout2->addWidget(edit2);
            } else if (isOk) {
                isOk = false;
                setWindowTitle(codec->toUnicode("Ошибка при создании layout2."));
            }

            // Горизонтальная группа для кнопок управления
            QHBoxLayout *layout3 = new QHBoxLayout();
            if (layout3) {
                layout3->addWidget(calcbutton);
                layout3->addWidget(exitbutton);
            } else if (isOk) {
                isOk = false;
                setWindowTitle(codec->toUnicode("Ошибка при создании layout3."));
            }

            layout4->addLayout(layout1);
            layout4->addLayout(layout2);
            layout4->addLayout(layout3);
        } else if (isOk) {
            isOk = false;
            setWindowTitle(codec->toUnicode("Ошибка при создании layout4."));
        }

        connect(calcbutton, &QPushButton::clicked, edit1, &Counter::add_one); // Нажатие кнопки "+1" вызывает увеличение первого счётчика
        connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one); // Сигнал tick_signal от первого счётчика вызывает увеличение второго
        connect(exitbutton, &QPushButton::clicked, this, &QWidget::close); // Нажатие кнопки "Выход" закрывает приложение
    }


}
