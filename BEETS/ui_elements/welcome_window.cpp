#include "welcome_window.h"
#include "ui_welcome_window.h"
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

    ui->stackedWidget->setCurrentIndex(0);
}

welcome_window::~welcome_window()
{
    delete ui;
}

void welcome_window::on_add_suite_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void welcome_window::on_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void welcome_window::on_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void welcome_window::on_continue_2_clicked()
{
    //creates a dynamiclly allocated testSuite with unique ptr so memory leaks are non-issue
    auto suite = std::make_unique<testSuite>(this->ui->comboBox->currentText());
    main_window* w = new main_window(nullptr, std::move(suite));
    this->close();
    w->show();
}

void welcome_window::on_save_cont_clicked()
{   
    if(!QFile::exists(ui->source_exe->text()))
    {
        QMessageBox::critical(this, "File Not Found", "Please check your path and try again");
        return;
    }
    auto suite = std::make_unique<testSuite>(ui->name->text(), ui->source_exe->text());
    main_window* w = new main_window(nullptr, std::move(suite));
    this->close();
    w->show();
}

void welcome_window::on_exit_clicked()
{
    exit(0);
}

void welcome_window::on_toolButton_clicked()
{

}
