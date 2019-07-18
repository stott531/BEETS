#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "testingSuite/testSuite.h"
#include <QListWidgetItem>

namespace Ui {
class main_window;
}


class main_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = nullptr, std::unique_ptr<testSuite> suite = nullptr);
    ~main_window();

private slots:
    void on_createTest_clicked();

    void on_testList_itemDoubleClicked(QListWidgetItem *item);

    void on_deleteTest_clicked();

    void on_saveTest_clicked();

    void on_saveTest_4_clicked();

    void on_runTests_clicked();

    void on_actionSave_triggered();

    void on_actionSave_and_Close_triggered();

private:
    Ui::main_window *ui;

    //main window should have the test suite as a member to operate on it
    std::unique_ptr<testSuite> suite;

    //test which we are currently editing
    Test currentTest;
};

#endif // MAIN_WINDOW_H
