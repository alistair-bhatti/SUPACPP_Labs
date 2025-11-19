#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

int cubeNum(int x){
    return x*x*x;
}

float cubeNum(float x){
    return x*x*x;
}

template<typename T>
T cubeNumTemplate(T);

template<typename T>
T cubeNumTemplate(T x){
    return x*x*x;
}


int main()
{
    // Function overlaoding: at compile time, function version is chosen based on number AND type of arguments: this is function overloading

    int x = 10;
    float y = 12.124214;

    std::cout << x << "^3 = " << cubeNum(x) << std::endl;
    std::cout << y << "^3 = " << cubeNum(y) << std::endl;

  
    return 0;
}

// g++ -std=c++20 -o L2_part2_examples_output L2_part2_examples.cxx