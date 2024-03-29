//Filip Soszynski

#ifndef BACA08_MAIN_H
#define BACA08_MAIN_H

#include <vector>

class spline{
private:
    int nodes_amount;
    std::vector<std::vector<double>> function;//Ax^2 + Bx + C
    std::vector<double> Y;//S(x)
    std::vector<double> T;//X
    std::

public:
    spline(int);

    void set_points( double[], double[]);

    double operator() (double) const;
};


#endif
