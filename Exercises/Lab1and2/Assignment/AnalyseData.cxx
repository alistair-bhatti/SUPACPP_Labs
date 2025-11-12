#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>







int main(){
std::string input_file = "input2D_float.txt";
std::ifstream data_file(input_file);
std::vector<float> new_vec;
std::vector< std::vector<float> > all_vecs; // 2D vector to store data from file

std::string line; //used to store each new line
while (std::getline(data_file, line)) { // , ','
    // std::cout << line << std::endl; // print each line to terminal
    // Is there a neater way to do this?
    size_t comma_pos = line.find(',');
    std::string x_str = line.substr(0, comma_pos);
    std::string y_str = line.substr(comma_pos + 1);
    if (x_str == "x" || y_str == "y") {
        continue; // skip empty lines
    }
    else {
    float x = std::stof(x_str);
    float y = std::stof(y_str);
    new_vec = {x, y};
    all_vecs.push_back(new_vec);
    int n = all_vecs.size();
    n -= 1; // adjust for 0 indexing!!!!!!!! .size() otuputs number of elements in human counting
    std::cout << "x: " << all_vecs[n][0] << ", y: " << all_vecs[n][1]  << std::endl;
    }

    }

data_file.close();
/*
std::cout << "Data read from file:" << std::endl;
for (auto dataVal : data) {
    std::cout << dataVal << std::endl;
}
*/


return 0;
}