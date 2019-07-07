#include "welcome_window.h"
#include "ui_welcome_window.h"
#include <QDir>
#include "testingSuite/testSuite.h"

welcome_window::welcome_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome_window)
{
    ui->setupUi(this);
    QDir dir("../etc");
    QStringList files = dir.entryList(QDir::Files);
    files.replaceInStrings(".JSON","");
    ui->comboBox->addItems(files);
    ui->comboBox_2->addItems(files);
}

welcome_window::~welcome_window()
{
    delete ui;
}

void welcome_window::on_add_suite_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void welcome_window::on_exit_clicked()
{
    exit(0);
}

void welcome_window::on_pushButton_2_clicked()
{
    exit(0);
}

void welcome_window::on_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void welcome_window::on_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void welcome_window::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString path = ui->source_exe->text();
    testSuite newTest(name, path);
    newTest.serialize();
}

void welcome_window::on_continue_2_clicked()
{
    //creates a dynamiclly allocated testSuite with unique ptr so memory leaks are non-issue
    auto suite = std::make_unique<testSuite>(this->ui->comboBox->currentText());
    main_window* w = new main_window(nullptr, std::move(suite));
    this->close();
    w->show();
}
