//
// Created by grant on 6/14/19.
//

//#include <stdio.h>
#include <iostream>
#include "testRedirection.h"

int main()
{
    //while (true)
    {
        int action;
        std::cout << "enter one of the following numbers\n"
                  << "0) exit\n"
                  << "1) File Redirection\n"
                  << "2) CMD Arguments\n";
        std::cin >> action;
        switch(action)
        {
            case 0: return 0;
            case 1:
                testRedirection();
                break;
//            case 2:
//                testCMD();
//                break;
        }


    }
}