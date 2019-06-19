//
// Created by stott on 6/17/19.
//

#ifndef BEETS_TESTSUITE_H
#define BEETS_TESTSUITE_H

#include <map>

#include "Test.h"

using std::string;
using std::map;


class testSuite {

public:
    //constructor from given values
    testSuite(const string &name, const string &pathToExe);

    //construct from a JSON file
    testSuite(const string &JSON_file);

    //runs all tests in the suite
    void run_tests();

    //serializes the test suite to a JSON file
    void serialize();

    //adds a test to the suite
    void addTest(const string& name, const Test& newTest);

    //remove a test from the suite
    void removeTest(const string& name);

    //change the a given test
    void updateTest(const string& name, const Test& newTest);



private:
    string name;
    string path_to_exe;
    map<string, Test> tests;
};


#endif //BEETS_TESTSUITE_H
