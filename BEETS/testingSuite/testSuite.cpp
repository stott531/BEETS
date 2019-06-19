//
// Created by stott on 6/17/19.
//

#include "testSuite.h"

testSuite::testSuite(const string &name, const string &pathToExe) : name(name), path_to_exe(pathToExe)
{
    this->tests = map<string, Test>();
}

testSuite::testSuite(const string &JSON_file) : name(name)
{

}

void testSuite::run_tests()
{

}

void testSuite::serialize()
{

}

void testSuite::addTest(const string &name, const Test &newTest)
{
    this->tests[name] = newTest;
}

void testSuite::removeTest(const string &name)
{
    this->tests.erase(name);
}

void testSuite::updateTest(const string &name, const Test &newTest)
{
    this->tests[name] = newTest;
}
