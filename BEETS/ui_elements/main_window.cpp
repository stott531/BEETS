#include "main_window.h"
#include "ui_main_window.h"

main_window::main_window(QWidget *parent, std::unique_ptr<testSuite> p_suite) :
    QMainWindow(parent),
    ui(new Ui::main_window),
    suite(std::move(p_suite))
{
    ui->setupUi(this);
    for(const auto& iter : suite->getTestMap().keys())
    {
        ui->testList->addItem(iter);
    }
    ui->editTestPane->setCurrentWidget(ui->Welcome);
}

main_window::~main_window()
{
    delete ui;
}

void main_window::on_createTest_clicked()
{
    //clear text boxes beforehand
    ui->nameLineEdit_4->clear();
    ui->cmd_lin_argsLineEdit_4->clear();
    ui->stdinLineEdit_4->clear();
    ui->stdoutLineEdit_4->clear();
    ui->answerLineEdit_4->clear();

    //display the widget
    ui->editTestPane->setCurrentWidget(ui->newTest);
}

void main_window::on_testList_itemDoubleClicked(QListWidgetItem *item)
{
    //get the double clicked test
    this->currentTest = suite->getTestMap()[item->text()];
    this->ui->testList->setCurrentItem(item);

    //set each text box to the Test's valuet
    ui->nameLineEdit->setText(this->currentTest.getName());
    ui->cmd_lin_argsLineEdit->setText(this->currentTest.getCmd_line_args());
    ui->stdinLineEdit->setText(this->currentTest.getStd_in());
    ui->stdoutLineEdit->setText(this->currentTest.getStd_out());
    ui->answerLineEdit->setText(this->currentTest.getAnswer());

    //display our work
    ui->editTestPane->setCurrentWidget(ui->editTest);
}

void main_window::on_deleteTest_clicked()
{
    suite->removeTest(this->currentTest.getName());
    ui->testList->takeItem(ui->testList->currentRow());
    ui->editTestPane->setCurrentWidget(ui->Welcome);
}

void main_window::on_saveTest_clicked()
{
    auto name = ui->nameLineEdit->text();
    suite->removeTest(name);
    suite->updateTest(name, Test(name,
                                 ui->cmd_lin_argsLineEdit->text(),
                                 ui->stdinLineEdit->text(),
                                 ui->stdoutLineEdit->text(),
                                 ui->answerLineEdit->text()));

    ui->testList->takeItem(ui->testList->currentRow());
    ui->testList->addItem(name);
    ui->editTestPane->setCurrentWidget(ui->Welcome);
}

void main_window::on_saveTest_4_clicked()
{
    suite->addTest(ui->nameLineEdit_4->text(), Test(ui->nameLineEdit_4->text(),
                                                     ui->cmd_lin_argsLineEdit_4->text(),
                                                     ui->stdinLineEdit_4->text(),
                                                     ui->stdoutLineEdit_4->text(),
                                                     ui->answerLineEdit_4->text()));
    ui->testList->addItem(ui->nameLineEdit_4->text());
    ui->editTestPane->setCurrentWidget(ui->Welcome);
}

void main_window::on_runTests_clicked()
{
    this->suite->run_tests();
    int row = 0;
    for (const auto& iter : this->suite->getTestMap().values()) {
        auto nameItem = new QTableWidgetItem(iter.getName());
        ui->testResults->setItem(row, 0, nameItem);

        auto passStatus = new QTableWidgetItem(iter.getPassedTest());
        ui->testResults->setItem(row, 1, passStatus);
    }
}



void main_window::on_actionSave_triggered()
{
    this->suite->serialize();
}

void main_window::on_actionSave_and_Close_triggered()
{
    this->suite->serialize();
}