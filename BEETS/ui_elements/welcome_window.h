#ifndef WELCOME_WINDOW_H
#define WELCOME_WINDOW_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>
#include "ui_elements/main_window.h"

namespace Ui {
class welcome_window;
}

class welcome_window : public QDialog
{
    Q_OBJECT

public:
    explicit welcome_window(QWidget *parent = nullptr);
    ~welcome_window();

private slots:
    void on_add_suite_clicked();

    void on_exit_clicked();

    void on_cancel_clicked();

    void on_cancel_2_clicked();

    void on_continue_2_clicked();

    void on_save_cont_clicked();

    void on_toolButton_clicked();

private:
    Ui::welcome_window *ui;
};

#endif // WELCOME_WINDOW_H
