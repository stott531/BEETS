#include "startingwindow.h"
#include "ui_startingwindow.h"
#include "createnewsuite.h"

startingWindow::startingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startingWindow)
{
    ui->setupUi(this);
}

startingWindow::~startingWindow()
{
    delete ui;
}

void startingWindow::on_removeSuite_2_clicked()
{
    exit(0);
}

void startingWindow::on_addSuite_clicked()
{
    auto d = new createNewSuite();
    d->show();
}
