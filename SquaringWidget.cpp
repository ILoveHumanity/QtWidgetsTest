#include "SquaringWidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

SquaringWidget::SquaringWidget(QWidget *parent) : QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8"); // Кодек для русификации интерфейса
    setWindowTitle(codec->toUnicode("Возведение в квадрат")); // Устанавливает заголовок окна
    isOk = true;
    //Для корректного выделения/освобождения памяти виджетов-детей при создании/уничтожении корневого виджета, подчиненные виджеты-компоненты размещают в динамической памяти.
    // Создаем рамку
    frame = new QFrame(this);
    if (frame) {
        frame->setFrameShadow(QFrame::Raised);
        frame->setFrameShape(QFrame::Panel);
    } else if (isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании рамки.")); // Устанавливает заголовок окна
    }


    // Создаем надпись для поля для ввода
    inputLabel = new QLabel(codec->toUnicode("Введите число:"), this);
    if(!inputLabel && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании надписи.")); // Устанавливает заголовок окна
    }

    // Создаем изменяемое поле для ввода
    inputEdit = new QLineEdit("",this);
    if(inputEdit) {
        StrValidator *v = new StrValidator(inputEdit);
        if (v) {
            inputEdit->setValidator(v); // Устанавливаем валидатор
            // Объект этого класса, включающего метод проверки вводимой строки validate(), передается строчному редактору, осуществляющему ввод.
            // При завершении ввода этот метод вызывается автоматически.
            // Поле обновляется только если валидатор возвращает Acceptable / Intermediate
            // Если этот метод возвращает Acceptable, то редактор ввода генерирует сигналы editingFinished()– завершение редактирования и
            // returnPressed()– сигнал нажатия клавиши Enter. В противном случае эти сигналы не генерируются.
        } else if(isOk) {
            isOk = false;
            setWindowTitle(codec->toUnicode("Ошибка при создании валидатора.")); // Устанавливает заголовок окна
        }
    } else if(isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании поля для ввода.")); // Устанавливает заголовок окна
    }

    // Создаем надпись для поля для вывода
    outputLabel = new QLabel(codec->toUnicode("Результат:"), this);
    if(!outputLabel && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании надписи.")); // Устанавливает заголовок окна
    }

    // Создаем изменяемое поле для вывода
    outputEdit = new QLineEdit("",this);
    if(!outputEdit && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании поля для вывода.")); // Устанавливает заголовок окна
    }

    // Создаем кнопки
    resetButton = new QPushButton(codec->toUnicode("Сбросить"), this);
    if(!resetButton && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании кнопки.")); // Устанавливает заголовок окна
    }

    exitButton = new QPushButton(codec->toUnicode("Выход"), this);
    if(!exitButton && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании кнопки.")); // Устанавливает заголовок окна
    }

    if (isOk) {
    // компоновка приложения выполняется согласно рисунку 2
//    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // Вертикальная группа 1 (ввод/вывод) внутри рамки
//    vLayout1->addWidget(inputLabel); // Добавляем надпись
//    vLayout1->addWidget(inputEdit); // Добавляем поле
//    vLayout1->addWidget(outputLabel); // Добавляем надпись 2
//    vLayout1->addWidget(outputEdit); // Добавляем поле
//    vLayout1->addStretch(); // Добовляем пружину (сдвигает от себя)

//    QVBoxLayout *vLayout2 = new QVBoxLayout(); // Вертикальная группа 2 (кнопки)
//    vLayout2->addWidget(resetButton); // Добавляем кнопку
//    vLayout2->addWidget(exitButton); // Добавляем кнопку
//    vLayout2->addStretch(); // Добавляем пружину (сдвигает от себя)

//    QHBoxLayout *hLayout = new QHBoxLayout(this); // Горизонтальная группа
//    hLayout->addWidget(frame); // Добавляем рамку
//    hLayout->addLayout(vLayout2); // Добавляем группу с кнопками


        if (frame) {
            QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // Вертикальная группа 1 (ввод/вывод) внутри рамки
            if(vLayout1) {
                vLayout1->addWidget(inputLabel); // Добавляем надпись
                vLayout1->addWidget(inputEdit); // Добавляем поле
                vLayout1->addWidget(outputLabel); // Добавляем надпись 2
                vLayout1->addWidget(outputEdit); // Добавляем поле
                vLayout1->addStretch(); // Добовляем пружину (сдвигает от себя)
            } else if (isOk) {
                isOk = false;
                setWindowTitle(codec->toUnicode("Ошибка при создании vLayout1.")); // Устанавливает заголовок окна
            }
        }

        QHBoxLayout *hLayout = new QHBoxLayout(this); // Горизонтальная группа
        if (hLayout) {
            hLayout->addWidget(frame); // Добавляем рамку

            QVBoxLayout *vLayout2 = new QVBoxLayout(); // Вертикальная группа 2 (кнопки)
            if(vLayout2) {
                vLayout2->addWidget(resetButton); // Добавляем кнопку
                vLayout2->addWidget(exitButton); // Добавляем кнопку
                vLayout2->addStretch(); // Добавляем пружину (сдвигает от себя)
            } else if (isOk) {
                isOk = false;
                setWindowTitle(codec->toUnicode("Ошибка при создании vLayout2.")); // Устанавливает заголовок окна
            }

            hLayout->addLayout(vLayout2); // Добавляем группу с кнопками
        } else if (isOk) {
            isOk = false;
            setWindowTitle(codec->toUnicode("Ошибка при создании hLayout.")); // Устанавливает заголовок окна
        }


        begin(); // Пересоздаем виджет

        // Соединяем сигналы со слотами
        connect(exitButton, &QPushButton::clicked, this, &SquaringWidget::close);
        connect(resetButton, &QPushButton::clicked, this, &SquaringWidget::begin);
        connect(inputEdit, &QLineEdit::returnPressed, this, &SquaringWidget::calc);
    }
}

void SquaringWidget::begin()
{
    if(isOk) {
        inputEdit->clear(); // Очищаем поле ввода от предыдущих значений
        resetButton->setEnabled(false); // Делаем кнопку "Сбросить" неактивной
        resetButton->setDefault(false); // Снимаем статус кнопки по умолчанию
        inputEdit->setEnabled(true); // Делаем поле ввода активным для нового ввода
        outputLabel->setVisible(false); // Скрываем надпись для поля вывода
        outputEdit->setVisible(false); // Скрываем поле для вывода результата
        outputEdit->setEnabled(false); // Делаем поле вывода неактивным
        inputEdit->setFocus(); // Передаем фокус ввода в поле inputEdit
    }
}

void SquaringWidget::calc()
{
    if(isOk) {
        bool Ok = true; double r,a; // Объявляем переменные для хранения чисел и флага успешного преобразования
        QString str = inputEdit->text(); // Получаем введенную строку из поля ввода
        a = str.toDouble(&Ok); // Пытаемся преобразовать строку в вещественное число типа double
        if (Ok) // Если преобразование прошло успешно (введено корректное число)
        {
            r=a*a; // Вычисляем квадрат введенного числа
            str.setNum(r); // Преобразуем полученный результат обратно в строку
            outputEdit->setText(str); // Выводим результат в поле outputEdit
            inputEdit->setEnabled(false); // Блокируем поле ввода, чтобы пользователь не мог изменить данные до сброса
            outputLabel->setVisible(true); // Отображаем надпись "Результат:"
            outputEdit->setVisible(true); // Отображаем поле с результатом
            resetButton->setDefault(true); // Назначаем кнопку "Сбросить" кнопкой по умолчанию (будет реагировать на Enter)
            resetButton->setEnabled(true); // Делаем кнопку "Сбросить" активной
            resetButton->setFocus(); // Передаем фокус на кнопку "Сбросить"
        }
        else if (!str.isEmpty()) // Если преобразование не удалось, проверяем, что строка не пустая (чтобы не выдавать ошибку при случайном нажатии Enter в пустом поле)
        {
            // Создаем объект информационного окна с заголовком и текстом ошибки
            QMessageBox msgBox(QMessageBox::Information, codec->toUnicode("Возведение в квадрат."), codec->toUnicode("Введено неверное значение."), QMessageBox::Ok);
            msgBox.exec(); // Запускаем цикл обработки событий для модального окна и ждем нажатия кнопки Ok пользователем
        }
    }
}


StrValidator::StrValidator(QObject *parent) : QValidator(parent) {}
StrValidator::State StrValidator::validate(QString &str,int &pos) const
{
//    bool Ok = true;
//    str.toDouble(&Ok);
//    if (Ok) {
//        return Acceptable; // метод принимает число типа double
//    }
//    return Intermediate;
    return Acceptable; // метод всегда принимает вводимую строку
}
