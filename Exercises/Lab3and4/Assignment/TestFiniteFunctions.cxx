#include "FiniteFunctions.h"
#include "CustomFunctions.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(){
    float R_min = -10.0;
    float R_max = 10.0;
    // create default FiniteFunction test object 
    FiniteFunction ff;
    ff.setRangeMin(R_min);
    ff.setRangeMax(R_max);
    ff.integral(10000); // compute integral with 10,000 divisions
    ff.setOutfile("test_function");
    //double normalisation_constant = 1/ff.integral(10000); // compute integral with 10,000 divisions
    ff.printInfo();


    // get a vector of pairs of points from scanFunction for this function: print the first five x,y pairs as a check
    /*
    std::vector< std::pair<double,double> > ff_points = ff.scanFunction();
    std::cout << "First 5 points of the function scan:" << std::endl;
    for (size_t i = 0; i < 5 && i < ff_points.size(); ++i) {
        std::cout << "x: " << ff_points[i].first << ", f(x): " << ff_points[i].second << std::endl; //.first . second as the is a pair, not vector!
    }
    */
    //ff.plotFunction();
    //FiniteFunction ff_from_Data(-10.0, 10.0, "ff_from_data");


    //read file data in to a single column
    std::vector< std::vector<float> > ff_points_from_data_raw = read_data("Outputs/data/MysteryData15020.txt");
    std::vector< double > ff_points_from_data;
    for (const auto& point_vec : ff_points_from_data_raw) {
        if (!point_vec.empty()) {
            ff_points_from_data.push_back(static_cast<double>(point_vec[0])); // assuming single column data
        }
    }



    //---
    // Create Histograms
    //---
    int N_bins = 50;
    ff.setOutfile("default function and data");



    
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Now testing default inv square distribution" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    //binned data
    ff.plotData(ff_points_from_data, N_bins, true);
    ff.plotFunction();
    //ff.plotData(ff_points_normalised, 50, false); // plot sampled points, N bins = 50, is data = false

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Now testing normal distribution" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    
    // create NormalDist object, with chosen mean & stddev
    double mean = 2.0;
    double stddev = 1.0;
    NormalDist nd(mean, stddev, R_min, R_max, "normal distribution");
    nd.setmean(mean);
    nd.setstddev(stddev);
    nd.integral(10000); // compute integral with 10,000 divisions
    nd.printInfo();
    nd.plotData(ff_points_from_data, N_bins, true); // plot data, is data = true
    nd.plotFunction();
    // default test function
    //ff.plotFunction(); // plot the default function: saves to Outputs/png/

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Now testing Cauchy-Lorentz distribution" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // create CauchyLorentz object, with chosen mean & stddev
    double gamma = 2.0;
    double x_0 = 0.5;
    CauchyLorentz cl(gamma, x_0, R_min, R_max, "cauchy-lorentz distribution");
    cl.setgamma(gamma);
    cl.setx_0(x_0);
    cl.integral(10000); // compute integral with 10,000 divisions
    cl.printInfo();
    cl.plotData(ff_points_from_data, N_bins, true); // plot data, is data = true
    cl.plotFunction();










    // print first 5 data points as a check
    /*
    std::cout << "First 5 data points from file:" << std::endl;
    
    for (size_t i = 0; i < 5 && i < data_points.size(); ++i) {
        std::cout << "Point " << i+1 << ": " << "x: " << data_points[i][0] << std::endl;
        }  
    */
    

    return 0;
}


/*    
//normalise: want integral equal to 1
double integral_value = ff.integral(10000); // calculate integral with 10,000 divisions
std::cout << "Calculated integral of the function: " << integral_value << std::endl;
std::vector< double > ff_points_normalised;
for (const auto& point : ff_points) {
    ff_points_normalised.push_back(point.second / integral_value); // normalise by dividing by the integral value
}
*/