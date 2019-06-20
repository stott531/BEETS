#ifndef STARTINGWINDOW_H
#define STARTINGWINDOW_H

#include <QDialog>

namespace Ui {
class startingWindow;
}

class startingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit startingWindow(QWidget *parent = nullptr);
    ~startingWindow();

private:
    Ui::startingWindow *ui;
};

#endif // STARTINGWINDOW_H
