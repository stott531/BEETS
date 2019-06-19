//
// Created by stott on 6/17/19.
//

#ifndef BEETS_TEST_H
#define BEETS_TEST_H

#include <string>

using std::string;

class Test {
public:
    //constructs from initializations
    Test(const string &name, const string &cmdLineArgs,
            const string &stdIn, const string &stdOut, const string &answer);

    //runs the test
    bool runTest();

private:
    string name, cmd_line_args, std_in, std_out, answer;
};


#endif //BEETS_TEST_H
