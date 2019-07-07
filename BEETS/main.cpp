#include "ui_elements/welcome_window.h"
#include <QApplication>

#include "testingSuite/testSuite.h"

int main(int argc, char *argv[])
{
    testSuite restored("foo_name");

    QApplication a(argc, argv);
    welcome_window w;
    w.show();




    return a.exec();
}
