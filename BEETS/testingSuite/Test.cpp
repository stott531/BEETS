//
// Created by stott on 6/17/19.
//

#include "Test.h"

Test::Test(const QString &name, const QString &cmdLineArgs, const QString &stdIn, const QString &stdOut, const QString &answer)
        : name(name), cmd_line_args(cmdLineArgs), std_in(stdIn), std_out(""), answer(answer), passedTest(false)
{

}

const QString& Test::getName() const
{
    return this->name;
}

const QString& Test::getCmd_line_args() const
{
    return this->cmd_line_args;
}

const QString& Test::getStd_in() const
{
    return this->std_in;
}

const QString& Test::getStd_out() const
{
    return this->std_out;
}

const QString& Test::getAnswer() const
{
    return this->answer;
}

bool Test::getPassedTest() const
{
    return this->passedTest;
}

void Test::set_path(const QString& path)
{
    this->path_to_exe = path;
}

QJsonValue Test::toJsonValue()
{
    QStringList members;
    members << cmd_line_args << std_in << std_out << answer;
    QJsonArray arr = QJsonArray::fromStringList(members);
    return QJsonValue(arr);
}

int Test::runTest()
{
    //create a new process
    auto testProcess = new QProcess();
    testProcess->setReadChannelMode(QProcess::SeparateChannels);

    //start the process with the given arguments
    testProcess->start(this->path_to_exe, cmd_line_args.split(' '));

    //wait for program to be ready to accept stdin
    QApplication::processEvents();
    testProcess->write(this->std_in.toUtf8(), this->std_in.size());
    testProcess->closeWriteChannel();

    //wait for program to process stdin
    testProcess->waitForReadyRead();
    this->std_out = testProcess->readAllStandardOutput();

    //learn how ternary operators work
    this->std_out == this->answer ? passedTest = true: passedTest = false;

    return 0;
}


bool Test::operator==(const Test& rhs) const
{
    return this->name == rhs.name &&
            this->answer == rhs.answer &&
            this->std_in == rhs.std_in &&
            this->std_out == rhs.std_out &&
            this->cmd_line_args == rhs.cmd_line_args;
}
