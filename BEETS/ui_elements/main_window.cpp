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
    ui->testResults->setHorizontalHeaderLabels(QStringList() << "Test" << "Result");
    ui->testResults->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
                                 "",
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
                                                     "",
                                                     ui->answerLineEdit_4->text()));
    ui->testList->addItem(ui->nameLineEdit_4->text());
    ui->editTestPane->setCurrentWidget(ui->Welcome);
}

void main_window::on_runTests_clicked()
{
    this->statusBar()->showMessage("Running Tests...", 2000);
    this->suite->run_tests();
    int row = 0, totalPassed = 0;

    ui->testResults->setRowCount(this->suite->getTestMap().size());
    ui->testResults->setColumnCount(2);

    for (const auto& iter : this->suite->getTestMap().values()) {

        auto nameItem = new QTableWidgetItem(iter.getName());
        ui->testResults->setItem(row, 0, nameItem);

        QString icon, status;
        if(iter.getPassedTest())
        {
            icon = ":/images/resources/green_check.png";
            status = "pass";
        } else {
            icon = ":/images/resources/red_cancel.png";
            status = "fail";
        }

        auto passStatus = new QTableWidgetItem(QIcon(icon), status);
        ui->testResults->setItem(row, 1, passStatus);

        if(iter.getPassedTest() == true) totalPassed++;
        row++;
    }
    this->ui->statusbar->showMessage("Passed "+QString::number(totalPassed)
                                     +"/"+QString::number(this->suite->getTestMap().size())
                                     +" Test Cases");
}


void main_window::on_actionSave_triggered()
{
    this->statusBar()->showMessage("Saving...", 2000);
    this->suite->serialize();
}

void main_window::on_actionSave_and_Close_triggered()
{
    this->statusBar()->showMessage("Saving...", 2000);
    this->suite->serialize();
    exit(0);
}

void main_window::on_actionChange_Executable_Path_triggered()
{
    bool okFile = false;
    QString newPath;
    do {
        newPath = QInputDialog::getText(this, "Change Path", "New Path:");
        QFile::exists(newPath) ? okFile = true : QMessageBox::critical(this, "File Not Found", "Please check your path and try again");

    } while(okFile == false);

    this->suite->setPath_to_exe(newPath);
}

void main_window::on_testResults_cellDoubleClicked(int row, int column)
{
    Test requestedTest = this->suite->getTestAt(this->ui->testResults->item(row, 0)->text());

    this->ui->answerEdit->setText(requestedTest.getAnswer());
    this->ui->stdoutEdit->setText(requestedTest.getStd_out());

    this->ui->editTestPane->setCurrentIndex(3);

}
