#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>


int main()
{
    // C-style strings, without external libraries:
    char buffer[100]; // num chars in buffer

    std::cout << "Enter your name: ";
    std::cin >> buffer; // read a string from standard input into buffer
    std::cout << "Hello, " << buffer << "!" << std::endl;


    // string class does more sureful stuff, saves manually defining everything:
    std::string my_strings[5] = {"H", "e", "l", "l", "o"}; // string class
    std::string my_string = "Hello";
    std::cout << "numebr of characters in my_string: " << my_string.length() << std::endl;
    if (my_strings[0] == "H") {
        std::cout << "first character is H" << std::endl;
    }
    // check for string to cotnain a cetain character
    // why dodes this not work...? my_string.find("e") returns not an int?
    /*
    if (my_string.find("e") != std::string::npos){
        printf("the string %s contains the eltter e in position %i\n", my_string.c_str(), my_string.find("e"));
    }
    */

    // Formatting output tricks:
    double pi = 3.14159265358979;
    std::cout << "pi = " << pi << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    std::cout << "pi = " << pi << std::endl;
    std::cout.unsetf(std::ios::fixed);
    std::cout.setf(std::ios::scientific);

    // 

    return 0;
}

// g++ -std=c++20 -o L2_part1_examples_output L2_part1_examples.cxx