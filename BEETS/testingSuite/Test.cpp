//
// Created by stott on 6/17/19.
//

#include "Test.h"

Test::Test(const QString &name, const QString &cmdLineArgs,
        const QString &stdIn, const QString &stdOut, const QString &answer)
        : name(name), cmd_line_args(cmdLineArgs), std_in(stdIn), std_out(stdOut), answer(answer)
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

const bool Test::getPassedTest() const
{
    return this->passedTest;
}

QJsonValue Test::toJsonValue()
{
    QStringList members;
    members << cmd_line_args << std_in << std_out << answer;
    QJsonArray arr = QJsonArray::fromStringList(members);
    return QJsonValue(arr);

}

void Test::runTest(QString path)
{
    auto testProcess = new QProcess();
    testProcess->start(path, cmd_line_args.split(' '));
    testProcess->write(this->std_in.toUtf8(), this->std_in.size());

    testProcess->waitForReadyRead();
    auto returned_output = testProcess->readAllStandardOutput();

    returned_output == answer ? passedTest = true: passedTest = false;

}
