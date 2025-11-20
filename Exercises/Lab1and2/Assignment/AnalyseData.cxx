#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "CustomFunctions.h"

// quick run command:
// g++ -std=c++20 -o AnalyseData_output AnalyseData.cxx CustomFunctions.cxx

int main(){
    // Get input file name from user, and set up key variables
    std::string input_file;
    std::cout << "Enter file to read from:" << std::endl;
    std::cin >> input_file;
    int num_lines;
    std::string choice;

    // get all points from vector object as a vector object in memory
    std::vector< std::vector<float> > data_vector = read_data(input_file);

    // main loop: prompts 4 options to user until they choose to quit
    bool go = true;
    while (go){

        // print options to user and wait for input of char correspoding to option
        std::cout << "\n --- \nPlease choose from the following options:\n" <<std::endl;
        std::cout << "a) print N lines of the read data to the screen" << std::endl;
        std::cout << "b) find the magnitude of all points" << std::endl;
        std::cout << "c) Fit a straight line to all points" << std::endl;
        std::cout << "d) calculate x^y for all points (where y rounded to nearest integer)" << std::endl;
        std::cout << "Q) Quit program" << std::endl;
        std::cout << "Please enter a/b/c/d/Q:" << std::endl;
        std::cin >> choice;

        if (choice == "a" || choice == "A"){
            std::cout << "You chose to print N lines of the data to the screen." << std::endl;
            std::cout << "Enter the number of lines from the file to display:" << std::endl;
            std::cin >> num_lines;
            print_data(data_vector, num_lines);
        } 
        if (choice == "b" || choice == "B"){
            std::cout << "You chose to calculate and print the magnitude of all points." << std::endl;
            std::vector<float> magnitudes = get_vector_magnitudes(data_vector);     // get all magnitudes as a vector
            print_file_lines(magnitudes); //<std::vector<float>>
            save_vector_to_file(magnitudes, "vector_magnitudes.txt");
        }
        if (choice == "c" || choice == "C"){
            // fit line to data and get line parameters: p, q, and chi^sqr
            std::vector<float> line_params = fit_line_to_Data(data_vector);
            std::cout << "You chose to fit a straight line to all points." << std::endl;
            std::cout << "Fitted line parameters (y = px + q):" << std::endl;
            std::cout << "p (slope): " << line_params[0] << std::endl;
            std::cout << "q (intercept): " << line_params[1] << std::endl;
            std::cout << "Chi-squared: " << line_params[2] << std::endl;
            std::cout << "y = " << line_params[0] << "x + " << line_params[1] << std::endl;
            save_fitted_line_to_file(line_params, "fitted_line.txt");
        }
        if (choice == "d" || choice == "D"){
            std::cout << "You chose to calculate x^y for all points (where y rounded to nearest integer)." << std::endl;
            std::vector<float> power_results = x_pow_y_calculator(data_vector);
            print_file_lines(power_results);
            save_vector_to_file(power_results, "x_pow_y_results.txt");
        }
        if (choice == "Q" || choice == "q"){
            std::cout << "Quitting program." << std::endl;
            go = false;
            break;
        }


    } // end of main while loop

return 0;
} // end of main