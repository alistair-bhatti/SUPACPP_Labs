#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include "FiniteFunctions.h"
#include "CustomFunctions.h"
#include <filesystem>
#pragma once

using std::filesystem::path;

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



/*


Normal distribution class inheriting from FiniteFunction


*/



NormalDist::NormalDist(){
    m_RMin = -5.0;
    m_RMax = +5.0;
    double m_Mean = 0.0;
    double m_StdDev = 1.0;
    this->checkPath("norm_default_output"); //Use provided string to name output files
}

NormalDist::NormalDist(double mean, double stddev, double range_min, double range_max, std::string outfile){
    m_RMin = range_min;
    m_RMax = range_max;
    double m_Mean = mean;
    double m_StdDev = stddev;
    this->checkPath(outfile); //Use provided string to name output files
}

void NormalDist::setmean(double mean) {m_Mean = mean;};
void NormalDist::setstddev(double stddev) {m_StdDev = stddev;};

double NormalDist::mean() {return m_Mean;};
double NormalDist::stddev() {return m_StdDev;};

void NormalDist::printInfo(){
    std::cout << "Normal Distribution Function Info:" << std::endl;
    std::cout << "Integral: " << m_Integral << ", calculated using " << m_IntDiv << " divisions" << std::endl;
    std::cout << "Mean: " << m_Mean << std::endl;
    std::cout << "Standard Deviation: " << m_StdDev << std::endl;
    std::cout << "Range Min: " << m_RMin << std::endl;
    std::cout << "Range Max: " << m_RMax << std::endl;
}



double NormalDist::norm_dist(double x, double m_Mean, double m_StdDev) {
        // Calculate the normal distribution value at x
    double coeff = 1.0 / (m_StdDev * std::sqrt(2.0 * M_PI));
    double exponent = -0.5 * std::pow((x - m_Mean) / m_StdDev, 2);
    return coeff * std::exp(exponent);

}

double NormalDist::callFunction(double x) {return this->norm_dist(x, m_Mean, m_StdDev);};



/*


Cauchy-Lorentz distribution class inheriting from FiniteFunction


*/




CauchyLorentz::CauchyLorentz(){
    m_RMin = -5.0;
    m_RMax = +5.0;
    double gamma = 1.0; // gamma > 0
    double x_0 = 0.0; // x_0 location offset
    this->checkPath("cauchy_default_output"); //Use provided string to name output files
}

CauchyLorentz::CauchyLorentz(double gamma, double x_0, double range_min, double range_max, std::string outfile){
    m_RMin = range_min;
    m_RMax = range_max;
    double m_gamma = gamma;
    double m_x_0 = x_0;
    this->checkPath(outfile); //Use provided string to name output files
}

void CauchyLorentz::setgamma(double gamma) {m_gamma = gamma;};
void CauchyLorentz::setx_0(double x_0) {m_x_0 = x_0;};

double CauchyLorentz::gamma() {return m_gamma;};
double CauchyLorentz::x_0() {return m_x_0;};

void CauchyLorentz::printInfo(){
    std::cout << "Cauchy-Lorentz Distribution Function Info:" << std::endl;
    std::cout << "Integral: " << m_Integral << ", calculated using " << m_IntDiv << " divisions" << std::endl;
    std::cout << "Gamma: " << m_gamma << std::endl;
    std::cout << "x_0: " << m_x_0 << std::endl;
    std::cout << "Range Min: " << m_RMin << std::endl;
    std::cout << "Range Max: " << m_RMax << std::endl;
}



double CauchyLorentz::cauchy_distr(double x, double m_gamma, double m_x_0) {
    // Calculate the Cauchy-lorentz distribution value at x
    double denom_1 = (m_gamma * M_PI);
    double denom_2 = 1 + std::pow((x - m_x_0) / m_gamma, 2);
    return (1/(denom_1 * denom_2));

}

double CauchyLorentz::callFunction(double x) {return this->cauchy_distr(x, m_gamma, m_x_0);};



/*


Crystal ball distribution class inheriting from FiniteFunction


*/


CrystalBall::CrystalBall(){
    m_RMin = -5.0;
    m_RMax = +5.0;
    double m_n = 2.0; // n > 1
    double m_alpha = 1.0; // alpha > 0
    double m_Mean = 0.0;
    double m_StdDev = 1.0;
    this->checkPath("crystal_default_output"); 
}

CrystalBall::CrystalBall(double n, double alpha, double mean, double stddev, double range_min, double range_max, std::string outfile){
    m_RMin = range_min;
    m_RMax = range_max;
    double m_n = n; // n > 1
    double m_alpha = alpha; // alpha > 0
    double m_Mean = mean;
    double m_StdDev = stddev;
    this->checkPath(outfile); //Use provided string to name output files
}

void CrystalBall::setn(double n) {m_n = n;};
void CrystalBall::setalpha(double alpha) {m_alpha = alpha;};
void CrystalBall::setmean(double mean) {m_Mean = mean;};
void CrystalBall::setstddev(double stddev) {m_StdDev = stddev;};

double CrystalBall::n() {return m_n;};
double CrystalBall::alpha() {return m_alpha;};
double CrystalBall::mean() {return m_Mean;};
double CrystalBall::stddev() {return m_StdDev;};

void CrystalBall::printInfo(){
    std::cout << "Crystal ball Distribution Function Info:" << std::endl;
    std::cout << "Integral: " << m_Integral << ", calculated using " << m_IntDiv << " divisions" << std::endl;
    std::cout << "n: " << m_n << std::endl;
    std::cout << "alpha: " << m_alpha << std::endl;
    std::cout << "mean: " << m_Mean << std::endl;
    std::cout << "StdDev: " << m_StdDev << std::endl; 
    std::cout << "Range Min: " << m_RMin << std::endl;
    std::cout << "Range Max: " << m_RMax << std::endl;
}



double CrystalBall::crystal_dist(double x, double n, double alpha, double mean, double stddev) {
    // Calculate the crystal ball distribution value at x
    // Huugely inefficient implementation, but works for now!
    double case_val = (x - mean) / stddev;
    double A = std::pow(n / std::abs(alpha), n) * std::exp(-0.5 * alpha * alpha);
    double B = n / std::abs(alpha) - std::abs(alpha);
    double C = n / std::abs(alpha) * 1.0 / (n - 1.0) * std::exp(-0.5 * alpha * alpha);
    double D = std::sqrt(M_PI / 2.0) * (1.0 + std::erf(alpha / std::sqrt(2.0)));
    double N = 1.0 / (stddev * (C + D));
    if (case_val > -alpha) {
        return N * std::exp(-0.5 * case_val * case_val);
    } else {
        return N * A * std::pow(B - case_val, -n);
    }

}

double CrystalBall::callFunction(double x) {return this->crystal_dist(x, m_n, m_alpha, m_Mean, m_StdDev);};



