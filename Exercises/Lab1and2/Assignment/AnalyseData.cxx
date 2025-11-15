#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "CustomFunctions.h"

// g++ -std=c++20 -o AnalyseData_output AnalyseData.cxx CustomFunctions.cxx

int main(){
    std::string input_file;
    std::cout << "Enter file to read from:" << std::endl;
    std::cin >> input_file;

    int num_lines;
    std::cout << "Enter the number of lines from the file to display:" << std::endl;
    std::cin >> num_lines;

    std::vector< std::vector<float> > data_vector = read_data(input_file);
    print_data(data_vector, num_lines);
    std::vector<float> magnitudes = get_vector_magnitudes(data_vector);


    std::vector<float> line_params = fit_line_to_Data(data_vector);
    save_fitted_line_to_file(line_params, "fitted_line.txt");

return 0;
}