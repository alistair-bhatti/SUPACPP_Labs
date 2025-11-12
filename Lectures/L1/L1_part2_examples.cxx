#include <iostream>
#include <vector>
#include <cmath>
#include <string>

//p52



float cubeNumber(float n){
    return n*n*n;
}

int main()
{
    float x = 3.0;
    float x3;
    x3 = cubeNumber(x);
    std::cout << "The cube of " << x << " is " << x3 << std::endl;

    return 0;
}