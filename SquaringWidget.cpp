#include "SquaringWidget.h"

SquaringWidget::SquaringWidget(QWidget *parent) : QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel(codec->toUnicode("Введите число:"), this);
    inputEdit = new QLineEdit("",this);
    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel(codec->toUnicode("Результат:"), this);
    outputEdit = new QLineEdit("",this);
    resetButton = new QPushButton(codec->toUnicode("Следующее"), this);
    exitButton = new QPushButton(codec->toUnicode("Выход"), this);
    // компоновка приложения выполняется согласно рисунку 2
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(resetButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();
    connect(exitButton, &QPushButton::clicked, this, &SquaringWidget::close);
    connect(resetButton, &QPushButton::clicked, this, &SquaringWidget::begin);
    connect(inputEdit, &QLineEdit::returnPressed, this, &SquaringWidget::calc);
}
void SquaringWidget::begin()
{
    inputEdit->clear();
    resetButton->setEnabled(false);
    resetButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}
void SquaringWidget::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);
    if (Ok)
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        resetButton->setDefault(true);
        resetButton->setEnabled(true);
        resetButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Возведение в квадрат."),
                               codec->toUnicode("Введено неверное значение."),
                               QMessageBox::Ok);
        msgBox.exec();
    }
}
