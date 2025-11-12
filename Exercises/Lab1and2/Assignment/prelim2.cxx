#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>


int main(){

    // define vector components and magnitude
    float x, y;
    x = 7.5;
    y = 3.4;

    // define vector using std::vector, and palceholder magnitude varaible
    std::vector<float> vec1; //no assignment
    vec1.push_back(x);
    vec1.push_back(y);
    float vec1_mag;

    // compute magnitude: a . a = |a|^2 -> mag_a = sqrt( a1^2 + a2^2 ) -> (This is obviously just pythagorus.)
    vec1_mag = std::sqrt( vec1[0]*vec1[0] + vec1[1]*vec1[1] );
    std:: cout << "The magnitude of the vector (" << vec1[0] << ", " << vec1[1] << ") is " << vec1_mag << std::endl;
}

