#include "FiniteFunctions.h"
#include "CustomFunctions.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(){

    // create FiniteFunction test object 
    FiniteFunction ff(-10.0, 10.0, "default_function");
    std::cout << "Function range: [" << ff.rangeMin() << ", " << ff.rangeMax() << "]" << std::endl;

    // get vector of pairs of points from scanFunction: print first five lines as a check
    std::vector< std::pair<double,double> > ff_points = ff.scanFunction();
    std::cout << "First 5 points of the function scan:" << std::endl;
    for (size_t i = 0; i < 5 && i < ff_points.size(); ++i) {
        std::cout << "x: " << ff_points[i].first << ", f(x): " << ff_points[i].second << std::endl; //.first . second as the is a pair, not vector!
    }

    ff.plotFunction();
    //normalise: want integral equal to 1
    double integral_value = ff.integral(10000); // calculate integral with 10,000 divisions
    std::cout << "Calculated integral of the function: " << integral_value << std::endl;
    std::vector< double > ff_points_normalised;
    for (const auto& point : ff_points) {
        ff_points_normalised.push_back(point.second / integral_value); // normalise by dividing by the integral value

    }
    std::cout << "integral of normalsied function: " << ff.integral(10000) << std::endl;



    FiniteFunction ff_from_Data(-10.0, 10.0, "ff_from_data");
    std::vector< std::vector<float> > ff_points_from_data_raw = read_data("Outputs/data/MysteryData15020.txt");
    std::vector< double > ff_points_from_data;
    for (const auto& point_vec : ff_points_from_data_raw) {
        if (!point_vec.empty()) {
            ff_points_from_data.push_back(static_cast<double>(point_vec[0])); // assuming single column data
        }
    }

    ff.plotData(ff_points_from_data, 50, true); // plot data, N bins = 50, is data = true
    ff.plotData(ff_points_normalised, 50, false); // plot sampled points, N bins = 50, is data = false
    ff.setOutfile("function_&_data");
    ff.plotFunction(); // plot the default function: saves to Outpus/png/


    // print first 5 data points as a check
    /*
    std::cout << "First 5 data points from file:" << std::endl;
    
    for (size_t i = 0; i < 5 && i < data_points.size(); ++i) {
        std::cout << "Point " << i+1 << ": " << "x: " << data_points[i][0] << std::endl;
        }  
    */
    

    return 0;
}