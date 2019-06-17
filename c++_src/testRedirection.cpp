//
// Created by grant on 6/16/19.
//

#include "testRedirection.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

void testRedirection()
{
    using namespace std;
    vector<string> vecArgv;
    string temp;

    cout << "input executable\n";
    cin >> temp;
    vecArgv.push_back(temp);

    temp = "<";
    vecArgv.push_back(temp);

    cout << "input redirected file\n";
    cin >> temp;
    vecArgv.push_back(temp);

    char** argv = (char**)malloc(3 * sizeof(char*));
    for (int i = 0; i <= 2; ++i)
    {
        argv[i] = (char*)(malloc(sizeof(vecArgv[i].c_str())));
    }


    for (int i = 0; i <= 2; i++)
    {
        argv[i] = (char*)vecArgv[i].c_str();
    }
    

}
