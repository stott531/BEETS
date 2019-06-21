//
// Created by stott on 6/17/19.
//

#include "testSuite.h"

#include <iostream>

testSuite::testSuite(const QString &name, const QString &pathToExe) : name(name), path_to_exe(pathToExe)
{
    this->tests = QMap<string, TestingClass>();
}

testSuite::testSuite(const QString& fileName)
{

}

void testSuite::run_tests()
{

}

void testSuite::serialize()
{
    QJsonObject json;
    json.insert("name", QJsonValue(this->name));
    json.insert("path_to_exe", QJsonValue(this->path_to_exe));

    for (auto test : this->tests) {
        json.insert(test.getName(), test.toJsonValue());
    }

    QJsonDocument file(json);
    QString fileName ="../etc/" + this->name + ".JSON";
    QFile newFile(fileName);
    newFile.open(QIODevice::WriteOnly);
    newFile.write(file.toJson());
    newFile.close();
}

void testSuite::addTest(const string &name, const Test &newTest)
{
    this->tests[name] = newTest;
}

void testSuite::removeTest(const string &name)
{
    this->tests.remove(name);
}

void testSuite::updateTest(const string &name, const Test &newTest)
{
    this->tests[name] = newTest;
}
