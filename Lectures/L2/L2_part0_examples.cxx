#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

void cubeInPlace(float&);

void cubeInPlace(float& x) {
    x = x * x * x;
}

int main()
{
    // p10ish Cube a  numebr in place in memory - passed by reference
    float x = 2.2;
    std::cout << x << "^3 = ";
    cubeInPlace(x);
    std::cout << x << std::endl;


    //  p13 Read a list of numbers from a text file into a vector
    // note this only gets the first number on each line of the file!
    // I have a versio nthe misses column headings  + gets multiple columns but nto as slick as this:
    // nto sure if there is a a way like thsi that is better 
    std::string inputgfile = "example_data.txt";
    std::ifstream data_file(inputgfile);
    std::vector<float> data;

    std::string line;
    while (std::getline(data_file, line)) { // get_line reads until new-line encoutnered and reads out as string
        data.push_back(std::stof(line)); // std::stof converts string to float
    }
    std::cout << "the data in the file is : " << std::endl;
    for (const auto& val : data) { // essentially a for loop over all elements in data: nto entirely clear how this works yet
        std::cout << val << std::endl;
    }

    data_file.close();

    // p18 write to file example
    std::string output_file_name = "output_data.txt";
    std::ofstream outStream; //ofstream object
    outStream.open(output_file_name, std::ios::app); // open the file: and append! without this ios::app it overwrites each time
    if (!outStream.is_open()) {
        std::cerr << "Error opening file for writing: " << output_file_name << std::endl;
        return -1;
    }
    else{
        std::cout << "Outut file " << output_file_name << " opened successfully!" << std::endl;
    }

    outStream << "# This is some output data\n";
    for (unsigned int i =1; i<=5; i++) {
        outStream << i << "\t," << i+1 << "\n"; // write two columns
    }   

    return 0;
}

// g++ -std=c++20 -o L2_part0_examples_output L2_part0_examples.cxx