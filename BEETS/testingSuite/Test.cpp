//
// Created by stott on 6/17/19.
//

#include "Test.h"

Test::Test(const QString &name, const QString &cmdLineArgs,
        const QString &stdIn, const QString &stdOut, const QString &answer)
        : name(name), cmd_line_args(cmdLineArgs), std_in(stdIn), std_out(stdOut), answer(answer)
{

}

QString Test::getName()
{
    return this->name;
}

QJsonValue Test::toJsonValue()
{
    QStringList members;
    members << cmd_line_args << std_in << std_out << answer;
    QJsonArray arr = QJsonArray::fromStringList(members);
    return QJsonValue(arr);

}

bool Test::runTest()
{
    return false;
}
