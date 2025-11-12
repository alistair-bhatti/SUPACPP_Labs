#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

float vectorMagnitude(std::vector<float> vec){
    return std::sqrt( vec[0]*vec[0] + vec[1]*vec[1] );
}

std::vector<float> getUserVector(){
    float x;
    float y;
    std::cout << "please enter x componenet of vector:" << std::endl;
    std::cin >> x;
    std::cout << "please enter y componenet of vector:" << std::endl;
    std::cin >> y;

    std::vector<float> vec;
    vec.push_back(x);
    vec.push_back(y);

    return vec;
}



int main(){

    std::vector<float> vec1 = getUserVector();
    float vec1_mag = vectorMagnitude(vec1);
    std::cout << "The magnitude of the vector (" << vec1[0] << ", " << vec1[1] << ") is " << vec1_mag << std::endl;
}

