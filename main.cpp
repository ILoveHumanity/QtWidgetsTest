#include <QApplication>
#include "Counter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win win;
    win.show();
    return a.exec();
}
