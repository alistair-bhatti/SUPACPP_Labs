#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cmath>

/*
read_data: reads data from a specified input file and stores it in a 2D vector.
Each line in the file is expected to contain two float values separated by a comma.
Parameters:
- input_file: A string representing the name of the input file to read data from.
Returns:
- a vector of pairs of floats e.g. a vector of x,y pairs.
*/
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

        // skip header line if present: this checks every line, so in theory is
        // quite inefficient, but for small files should be ok
        // alternatively could be examples to e.g. made sure no non-numeric data is read in
        if (x_str == "x" || y_str == "y") {
            continue; // skip empty lines
        }
        else {
        float x = std::stof(x_str);
        float y = std::stof(y_str);
        new_vec = {x, y};

        all_vecs.push_back(new_vec);


        // This prints each line to the terminal as it reads the file:
        // Used for testing funcion works correctly
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


float chi_sqrd_test(const std::vector< std::vector<float> > data, const std::vector<float> line_params){
    // calculate chi squared value for the line fit to the data
    // chi^2 = sum((y_i - (px_i + q))^2 / sigma_i^2)
    // assuming sigma_i = 1 for all points
    int M = data.size();
    float chi_sqrd = 0.0;
    float p = line_params[0];
    float q = line_params[1];

    std::vector< std::vector<float> > standard_error = read_data("error2D_float.txt");
    int S = standard_error.size();
    if (S != M){
        std::cerr << "Error: error file does not contain the correct number of lines." << std::endl;
        std::cerr << "Expected " << M << " lines, but got " << S << " lines." << std::endl;
        return -1.0;
    }

    for (int i=0; i<M; i++){
        float x = data[i][0];
        float y = data[i][1];
        float y_fitted = p * x + q;
        chi_sqrd += ((y - y_fitted) * (y - y_fitted)) / (standard_error[i][0]); // 
    }

    return chi_sqrd;
}

float x_pow_y_cal(float x, int y){
    // calculate x^y without using in-built pow or for loops
    if (y == 0){ // many data points from input2D_float.txt will round to y=0
        return 1.0;
    }
    else if (y < 0){ // no -ve poitns in the file, but there could be!
        return 1.0 / x_pow_y_cal(x, -y);
    }
    else{ //"normal" case
        return x * x_pow_y_cal(x, y - 1);
    }
}

std::vector<float> x_pow_y_calculator(const std::vector< std::vector<float> > &data){
    // calculate x^y for each data point without using a for loop or any in-built power functions
    // using std::transform and a lambda function
    std::vector<float> x_pow_y;
    int M = data.size();
    x_pow_y.resize(M); // single column, same size at ttohe number of data points

    for (int i=0; i<M; i++){ // loop is to get x^y all points, but each point does not use a loop or pow function
        float x = data[i][0]; //select row then column
        int y = std::round(data[i][1]);

        x_pow_y[i] = x_pow_y_cal(x, y); // The power x^y is calcualted without use of pow or a for loop: used recursion
    }
    return x_pow_y;
}

std::vector<float> fit_line_to_Data(const std::vector< std::vector<float> > &data){
    // fit a line to the data using least squares regression
    // y = px + q (y = mx + c)
    // return m and c as a vector of floats
    int N = data.size(); //number of pairs of points
    float sum_x = 0.0;
    float sum_y = 0.0;
    float sum_xy = 0.0;
    float sum_x2 = 0.0;

    for (int i=0; i<N; i++){
        float x = data[i][0];
        float y = data[i][1];
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
    }

    float p = ((N * sum_xy) - (sum_x * sum_y)) / ((N * sum_x2) - (sum_x * sum_x));
    float q = ((sum_x2 * sum_y) - (sum_xy * sum_x)) / ((N * sum_x2) - (sum_x * sum_x));

    float chi_sqrd = chi_sqrd_test(data, {p, q});
    std::vector<float> line_params = {p, q, chi_sqrd}; // m and c
    return line_params; 

}



void save_fitted_line_to_file(const std::vector<float> &line_params, const std::string &output_file){
    std::ofstream out_file(output_file);
    if (out_file.is_open()){
        out_file << "Fitted line parameters (y = px + q):" << std::endl;
        out_file << "p (slope): " << line_params[0] << std::endl;
        out_file << "q (intercept): " << line_params[1] << std::endl;
        out_file << "Chi-squared: " << line_params[2] << std::endl;
        out_file << "y = " << line_params[0] << "x + " << line_params[1] << std::endl;
        out_file.close();
        std::cout << "Fitted line parameters saved to file: " << output_file << std::endl;
        std::cout << "chi^2:" << line_params[2] << std::endl;
        std::cout << "y = " << line_params[0] << "x + " << line_params[1] << std::endl;
    }
    else {
        std::cerr << "Error: Could not open file " << output_file << " for writing." << std::endl;
    }
}

void save_vector_to_file(const std::vector<float> &data, const std::string &output_file){
    std::ofstream out_file(output_file);
    if (out_file.is_open()){
        for (const auto &val : data){
            out_file << val << std::endl;
        }
        out_file.close();
        std::cout << "Data saved to file: " << output_file << std::endl;
    }
    else {
        std::cerr << "Error: Could not open file " << output_file << " for writing." << std::endl;
    }
}

/*
// Why didn't this function work wheras non-tempalte version below does?
template<typename T>
void print_file_lines(T data){
    for (auto &i : data) {
        std::cout << i << std::endl;
    }
}


*/

void print_file_lines(std::vector<float> magnitude_data){
    for (auto &i : magnitude_data) {
        std::cout << i << std::endl;
    }
}
