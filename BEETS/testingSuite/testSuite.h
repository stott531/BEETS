//
// Created by stott on 6/17/19.
//

#ifndef BEETS_TESTSUITE_H
#define BEETS_TESTSUITE_H


#include "Test.h"
#include <QMap>
#include <QJsonObject>
#include <QJsonDocument>
#include <memory>
#include <QMessageBox>
#include <QtConcurrentRun>
#include <functional>


class testSuite {

public:
    //constructor from given values
    testSuite(const QString &name, const QString &pathToExe);

    //construct from a JSON file
    testSuite(const QString& fileName);

    testSuite() = default;

    //runs all tests in the suite
    void run_tests();

    //serializes the test suite to a JSON file
    void serialize();

    //adds a test to the suite
    void addTest(const QString& name, const Test& newTest);

    //remove a test from the suite
    void removeTest(const QString& name);

    //change the a given test
    void updateTest(const QString& name, const Test& newTest);

    //get the testing map
    const QMap<QString, Test>& getTestMap() const;

    //get the name
    const QString getName() const;

    //set the executble path
    void setPath_to_exe(const QString& newPath);

    static void runTestStatic(QString path, Test curTest);

    Test getTestAt(const QString& requestedTest);

    bool operator==(const testSuite& rhs) const;


private:
    QString name;
    QString path_to_exe;
    QMap<QString, Test> tests;
};


#endif //BEETS_TESTSUITE_H
