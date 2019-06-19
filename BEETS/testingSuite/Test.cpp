//
// Created by stott on 6/17/19.
//

#include "Test.h"

Test::Test(const std::string &name, const std::string &cmdLineArgs,
        const std::string &stdIn, const std::string &stdOut, const std::string &answer)
        : name(name), cmd_line_args(cmdLineArgs), std_in(stdIn), std_out(stdOut), answer(answer)
{

}

bool Test::runTest()
{
    return false;
}
