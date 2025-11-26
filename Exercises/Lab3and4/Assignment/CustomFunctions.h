#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cmath>

#include "FiniteFunctions.h"
#pragma once

std::vector< std::vector<float> > read_data(const std::string &input_file="input2D_float.txt");

class NormalDist : public FiniteFunction {
public:
    NormalDist();
    NormalDist(double mean, double stddev, double range_min, double range_max, std::string outfile);
    double mean();
    double stddev();
    void setmean(double mean);
    void setstddev(double stddev);
    double norm_dist(double x, double mean, double stddev);
    virtual double callFunction(double x) override; // Override the callFunction method
    virtual void printInfo() override; // Override the printInfo method
protected:
    double m_Mean;
    double m_StdDev;

};


class CauchyLorentz : public FiniteFunction {
public:
    CauchyLorentz();
    CauchyLorentz(double gamma, double x_0, double range_min, double range_max, std::string outfile);
    double gamma();
    double x_0();
    void setgamma(double gamma);
    void setx_0(double x_0);
    double cauchy_distr(double x, double gamma, double x_0);
    virtual double callFunction(double x) override; // Override the callFunction method
    virtual void printInfo() override; // Override the printInfo method
protected:
    double m_gamma;
    double m_x_0;
    
};



class CrystalBall : public FiniteFunction {
public:
    CrystalBall();
    CrystalBall(double n, double alpha, double mean, double stddev, double range_min, double range_max, std::string outfile);
    double n();
    double alpha();
    double mean();
    double stddev();
    void setn(double n);
    void setalpha(double alpha);
    void setmean(double mean);
    void setstddev(double stddev);
    double crystal_dist(double x, double n, double alpha, double mean, double stddev);
    virtual double callFunction(double x) override; // Override the callFunction method
    virtual void printInfo() override; // Override the printInfo method
protected:
    double m_n;
    double m_alpha;
    double m_Mean;
    double m_StdDev;

};