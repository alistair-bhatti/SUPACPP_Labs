#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cmath>

std::vector< std::vector<float> >  read_data(const std::string &input_file){
    std::cout << "Reading data from file: " << input_file << std::endl;
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


        //This prints each line to the terminal as it reads the file
        /*
        int n = all_vecs.size();
        n -= 1; // adjust for 0 indexing!!!!!!!! .size() otuputs number of elements in human counting
        std::cout << "x: " << all_vecs[n][0] << ", y: " << all_vecs[n][1]  << std::endl;
        */
        }
    }
    data_file.close();
    std::cout << "Finished reading data from file." << std::endl;
    return all_vecs;
}

void print_data(const std::vector< std::vector<float> > &data, int N_lines){
    std::cout << "Printing first " << N_lines << " lines of data:" << std::endl;
    int total_lines = data.size();
    if (N_lines > total_lines){
        N_lines = total_lines;
        std::cout << "Note: there are only " << total_lines << " lines of data available." << std::endl;
    }
    for (int i=0; i<N_lines; i++){
        std::cout << "line " << i+1 << ", x: " << data[i][0] << ", y: " << data[i][1]  << std::endl;
    }
}

std::vector<float> get_vector_magnitudes(const std::vector< std::vector<float> > &all_vecs){
    std::vector<float> vec_magnitudes;
    int number_vecs = all_vecs.size();
    float new_vec_mag;
    for (int i=0; i<number_vecs; i++){
        std::vector<float> vec = all_vecs[i];
        new_vec_mag = std::sqrt( vec[0]*vec[0] + vec[1]*vec[1] );
        vec_magnitudes.push_back(new_vec_mag);

        // print to screen checking magnitudes calculated correctly
        // std::cout << "The magnitude of vector " << i+1 << " (" << vec[0] << ", " << vec[1] << ") is " << new_vec_mag << std::endl;
    }
    // 

    return vec_magnitudes;
}