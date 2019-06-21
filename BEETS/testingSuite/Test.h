//
// Created by stott on 6/17/19.
//

#ifndef BEETS_TEST_H
#define BEETS_TEST_H

#include <QString>
#include <QStringList>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>


class Test {
public:
    //constructs from initializations
    Test(const QString &name, const QString &cmdLineArgs,
            const QString &stdIn, const QString &stdOut, const QString &answer);

    QJsonValue toJsonValue();

    Test() = default;
    QString getName();
    //runs the test
    bool runTest();

private:
    QString name, cmd_line_args, std_in, std_out, answer;
};


#endif //BEETS_TEST_H
