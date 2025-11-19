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
    std::string choice;

    // get all points as a vector
    std::vector< std::vector<float> > data_vector = read_data(input_file);
    //get all magnitudes as a vector
    std::vector<float> magnitudes = get_vector_magnitudes(data_vector);

    std::cout << "Do you want to \na) print N lines of the data to the screen?\nb) print the magnitude of all points?\nenter a/b:" << std::endl;
    std::cin >> choice;
    if (choice == "a"){
        std::cout << "You chose to print N lines of the data to the screen." << std::endl;
        std::cout << "Enter the number of lines from the file to display:" << std::endl;
        std::cin >> num_lines;
        print_data(data_vector, num_lines);
    } 
    if (choice == "b"){
        std::cout << "You chose to print the magnitude of all points." << std::endl;
        print_file_lines(magnitudes); //<std::vector<float>>
    }

    std::vector<float> line_params = fit_line_to_Data(data_vector);
    save_fitted_line_to_file(line_params, "fitted_line.txt");



return 0;
}