#include <iostream> 
#include <vector> // defined in the std:: namespace
#include <cmath>
#include <string.h>
// #include <math> - does this exist in C++?

// the are all preprocessor directives: executed at compile time, nto runtime
// Adds functionality from toher code libraries: equivalent of Python import
// iostream is in / out for terminal, reading objects into the script


/* could avoid using "std::" everywhere by using following line:

using namespace std;

may impeded understadning if not careful!
*/

int main()
// Functions MUST return: for main must be int
// return 0 means no errors
{
    //Print "hello world!" to the terminal
    std::cout << "hello world!" << std::endl;
    // cout: sneds str to stadnard output (the terminal), from iostream library
    // << shift oeprator: sneds strings to cout
    // endl prints a new line -> kind of like + in python?
    // std:: namespace in whcih count defined. could write another func named cout and compiler would not be confused

    int A = 5; // combined declaration & assignment
    //variabels msut start with a letter or _

    std::cout << "A = " << A << std::endl;


    double x, y, z;
    x = 1.5;
    y = 2.1;
    z = x + y;
    std::cout << "z = " << z << std::endl;
    z = z + 9.3;
    std::cout << "now z = " << z << std::endl;

    // can use auto:
    auto B = false;
    auto C = 1+2;
    auto D = 6.9/4;

    std::cout << "type of B = " << typeid(B).name() << std::endl;
    std::cout << "type of C = " << typeid(C).name() << std::endl;
    std::cout << "type of D = " << typeid(D).name() << std::endl;

    std::string name = "John Doe";
    std::vector<float> numbers; //no assignment
    numbers.push_back(1.1);
    numbers.push_back(2.3);
    numbers.push_back(7.8);

    std:: cout << "numbers: " << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << ", " << std::endl;

    std::vector<std::string> names = {"John Doe", "Jane Doe"}; // access these elements just as with the numbers elements


    // use const to ensure value cannot be changed, e.g.:
    const double PI = 3.14159265;

    std::cout << "PI = " << PI << std::endl;

    // oeprators largeyl the same as python for evaluation
    // note that n = i++ means n = i, i=i+1
    // wheras n = ++i means i=i+1, n=i
    // other shorthands exist: tend to prefer clarity

    int a = sizeof(int); // size in bytes of int type
    std::cout << "size of int = " << a << " bytes" << std::endl;

    //p37
    // Bitwise operators also exist: &, |, ^, ~, <<, >>, but can be dangerous!

    char n[1];
    std::cout << "please enter a character (a-z), and hit return:" << std::endl;
    std::cin >> n[0]; // read from standard input (terminal) into variable a
    if (strcmp("n",n) ==0){
        std::cout << "you entered a!" << std::endl;
    }
    if (strcmp("n",n) != 0){
        std::cout << "you entered a!" << std::endl;
    }   

    // p41 loops
    std::cout << "While loop counting to 5 (0-4)" << std::endl;
    int i =0;
    int nMax = 5;
    while (i < nMax){
        std::cout << "i = " << i << std::endl;
        i += 1;
    }

    // can aslo do e.g. do { ... } while (condition);
    // and for: e.g. 
     
    int nsum = 0;
    int m = 9;
    for (int i=0; i<=m; i++){
        nsum += i;
    }
    std::cout << "sum of integers 0-" << m << " = " << nsum << std::endl;
    

        // use :: to access gloabl namespace if needed
    return 0;

}

// comment like this 
/* or like this
for multiline
comments */