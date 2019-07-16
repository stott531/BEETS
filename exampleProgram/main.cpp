#include <iostream>
#include <cstring>

/* This simple program is for testing purposes
 *
 * It finds the area of a circle or a rectangle
 * Circle or square is specified in command line args
 * Dimensions will be passed in via stdin
 * Area will be returned via stdout
 */

int main(int argc, char** argv)
{
    if(strncmp(argv[1], "circle", 6) == 0)
    {
        double radius;
        std::cin >> radius;

        std::cout << radius * 3.14159265359;
    }
    else if(strncmp(argv[1], "square", 6) == 0)
    {
        double side;
        std::cin >> side;

        std::cout << side * side;
    }
    else
    {
        std::cout << "Invalid input \n";
    }

    return 0;
}