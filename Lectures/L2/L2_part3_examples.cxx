#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>



int main()
{
    // p31 pointers & arrays
    int myArray[5] = {10, 20, 30, 40, 50};
    int myarray2[3];

    std::cout << "myArray address: " << myArray << std::endl;
    std::cout << "myArray contains: ";
    for (int i=0; i < (sizeof(myArray)/sizeof(int)); i++){
        std::cout << myArray[i] << " ";
    std::cout << std::endl;
    }
    



    return 0;
}

// g++ -std=c++20 -o L2_part3_examples_output L2_part3_examples.cxx