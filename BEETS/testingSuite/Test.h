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
    friend class testSuite;

    //constructs from initializations
    Test(const QString &name, const QString &cmdLineArgs, const QString &stdIn, const QString &stdOut, const QString &answer);

    //convert the test to a JSON value
    QJsonValue toJsonValue();

    //empty constructor
    Test() = default;

    //getters
    const QString& getName() const;
    const QString& getCmd_line_args() const;
    const QString& getStd_in() const;
    const QString& getStd_out() const;
    const QString& getAnswer() const;
    bool getPassedTest() const;

    //set the path
    void set_path(const QString& path);

    //comparison operator for testing purposes
    bool operator==(const Test& rhs) const;

    //runs the test
    int runTest();


private:
    QString name;
    QString cmd_line_args;
    QString std_in;
    QString std_out;
    QString answer;
    QString path_to_exe;
    bool passedTest;
};


#endif //BEETS_TEST_H
