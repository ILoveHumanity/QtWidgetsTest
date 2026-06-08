#include "Window.h"
#include <QVBoxLayout>

Window::Window()
{
    codec = QTextCodec::codecForName("UTF-8");
    this->setWindowTitle(codec->toUnicode("Обработка событий"));
    bool isOk = true;

    area = new Area( this );
    if (!area && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании области отображения."));
    }

    btn = new QPushButton(codec->toUnicode("Завершить"),this );
    if (!btn && isOk) {
        isOk = false;
        setWindowTitle(codec->toUnicode("Ошибка при создании кнопки завершения."));
    }

    if(isOk) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        if (!layout) {
            setWindowTitle(codec->toUnicode("Ошибка при создании layout."));
        } else {
            layout->addWidget(area);
            layout->addWidget(btn);
        }
        connect(btn, &QPushButton::clicked, this, &QWidget::close);
    }
};

