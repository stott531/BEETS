#include "ui_elements/startingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startingWindow w;
    w.show();

    return a.exec();
}
