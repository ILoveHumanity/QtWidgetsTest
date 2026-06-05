#include <QApplication>
#include "SquaringWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SquaringWidget squaringWidget;
    squaringWidget.show();
    return a.exec();
}
