#include "cliptor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cliptor w;
    w.show();

    return a.exec();
}
