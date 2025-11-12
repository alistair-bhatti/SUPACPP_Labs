#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cmath>


std::vector< std::vector<float> > read_data(const std::string &input_file="input2D_float.txt");

void print_data(const std::vector< std::vector<float> > &data=read_data(), int N_lines=5);


std::vector<float> get_vector_magnitudes(const std::vector< std::vector<float> > &all_vecs=read_data());




