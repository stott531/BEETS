//
// Created by stott on 6/17/19.
//

#include "testSuite.h"

#include <iostream>

testSuite::testSuite(const string &name, const string &pathToExe) : name(name), path_to_exe(pathToExe)
{
    this->tests = QMap<string, TestingClass>();
}

testSuite::testSuite(const string &JSON_file)
{
    std::cout << JSON_file;
}

void testSuite::run_tests()
{

}

void testSuite::serialize(const string& directoryPath)
{

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
