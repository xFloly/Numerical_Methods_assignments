//Filip Soszynski
#include "source.h"
#include <iostream>
#include <vector>
#include <cmath>


spline::spline(int n) {
    nodes_amount = n;
    function = std::vector<std::vector<double>>(n);
    Y = std::vector<double>(n);
    T = std::vector<double>(n);

    for(auto& a : function){
        a = std::vector<double>(3);
    }

}

void spline::set_points(double t[], double y[]) {
    std::vector<double> h = std::vector<double>(nodes_amount);
    std::vector<double> b = std::vector<double>(nodes_amount);
    std::vector<double> u = std::vector<double>(nodes_amount);
    std::vector<double> v = std::vector<double>(nodes_amount);
    std::vector<double> z = std::vector<double>(nodes_amount);


    for(int i = 0; i < nodes_amount-1; i++){
        h[i] = t[i+1] - t[i];
        b[i] = 6*(y[i+1]-y[i])/h[i];
    }

    u[1] = 2*(h[0]+h[1]);
    v[1] = b[1]-b[0];
    for(int i = 2; i < nodes_amount-1; i++){
        u[i] = 2*(h[i-1] + h[i]) - pow(h[i-1],2)/u[i-1];
        v[i] = b[i] - b[i-1] - (h[i-1]*v[i-1])/u[i-1];
    }

    z[nodes_amount-1] = 0;
    for(int i = nodes_amount-2; i > 0; i--){
        z[i] = (v[i] - h[i]*z[i+1])/u[i];
    }
    z[0] = 0;

    for(int i = 0; i < nodes_amount; i++){
        function[i][0] = ( 1 / (6*h[i]) ) * (z[i+1]-z[i]);
        function[i][1] = z[i]/2;
        function[i][2] = (1/h[i]) * (y[i+1]-y[i]) -  ( h[i]/6 ) * (z[i+1]+2*z[i]);
        T[i] = t[i];
        Y[i] = y[i];
    }
}

double spline::operator()(double z) const {
    int i = nodes_amount-1;
    while(z - T[i] < 0 && i > 0)
        i--;

    return Y[i] + (z-T[i]) * (function[i][2] + (z-T[i]) * (function[i][1] + (z-T[i]) * function[i][0]));
}