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
#include <QProcess>
#include <QApplication>


class Test {
public:
    //constructs from initializations
    Test(const QString &name, const QString &cmdLineArgs, const QString &stdIn, const QString &stdOut, const QString &answer);

    QJsonValue toJsonValue();

    Test() = default;

    //getters
    const QString& getName() const;
    const QString& getCmd_line_args() const;
    const QString& getStd_in() const;
    const QString& getStd_out() const;
    const QString& getAnswer() const;
    bool getPassedTest() const;

    //runs the test
    void runTest(QString path);


private:
    QString name, cmd_line_args, std_in, std_out, answer;
    bool passedTest;
};


#endif //BEETS_TEST_H
