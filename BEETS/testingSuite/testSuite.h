//
// Created by stott on 6/17/19.
//

#ifndef BEETS_TESTSUITE_H
#define BEETS_TESTSUITE_H


#include "Test.h"
#include <QMap>
#include <QJsonObject>
#include <QJsonDocument>


typedef Test TestingClass;


class testSuite {

public:
    //constructor from given values
    testSuite(const QString &name, const QString &pathToExe);

    //construct from a JSON file
    testSuite(const QString& fileName);

    //runs all tests in the suite
    void run_tests();

    //serializes the test suite to a JSON file
    void serialize();

    //adds a test to the suite
    void addTest(const QString& name, const Test& newTest);

    //remove a test from the suite
    void removeTest(const QString& name);

    //change the a given test
    void updateTest(const QString& name, const TestingClass& newTest);



private:
    QString name;
    QString path_to_exe;
    QMap<QString, TestingClass> tests;
};


#endif //BEETS_TESTSUITE_H
