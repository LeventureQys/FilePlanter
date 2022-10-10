#include "FilePlanter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentFileTransfer w;
    w.show();
    return a.exec();
}
