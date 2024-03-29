//Filip Soszynski
#include <iostream>
#include <cmath>
#include <iomanip>
#include "funkcja.h"

struct Jet{
    double f;
    double fx;
    double fy;
    double fxx;
    double fxy;
    double fyy;

    Jet()= default;
    Jet(const Jet& jet){
        f = jet.f;
        fx = jet.fx;
        fy = jet.fy;
        fxx = jet.fxx;
        fxy = jet.fxy;
        fyy = jet.fyy;
    }
    Jet(double f, double fx, double fy, double fxx, double fxy, double fyy) {
        this->f = f;
        this->fx = fx;
        this->fy = fy;
        this->fxx = fxx;
        this->fxy = fxy;
        this->fyy = fyy;
    }
    Jet(double x){
        f = x;
        fx = 0;
        fy = 0;
        fxx = 0;
        fxy = 0;
        fyy = 0;
    }
};

Jet operator-(const Jet& x){
    return {
            -x.f,
            -x.fx,
            -x.fy,
            -x.fxx,
            -x.fxy,
            -x.fyy
    };
}

Jet operator+(const Jet& x,const Jet& y){
    return {x.f+y.f,
            x.fx+y.fx,
            x.fy+y.fy,
            x.fxx+y.fxx,
            x.fxy+y.fxy,
            x.fyy+y.fyy};
}

Jet operator-(const Jet& x,const Jet& y){
    return {x.f-y.f,
            x.fx-y.fx,
            x.fy-y.fy,
            x.fxx-y.fxx,
            x.fxy-y.fxy,
            x.fyy-y.fyy};
}

Jet operator*(const Jet& x,const Jet& y)
{
return {
    x.f*y.f,
    x.fx*y.f + x.f*y.fx,
    x.fy*y.f + x.f*y.fy,
    x.fxx*y.f + 2*x.fx*y.fx + x.f*y.fxx,
    x.fxy*y.f + x.fx*y.fy + x.fy*y.fx + x.f*y.fxy,
    x.fyy*y.f + 2*x.fy*y.fy+x.f*y.fyy
};
}

Jet operator/(const Jet& x,const Jet& y){
    double yf2 = y.f * y.f;
    double yf3 = yf2 * y.f;
    return{
        x.f/y.f,
        (x.fx*y.f - x.f*y.fx) / yf2,
        (x.fy*y.f - x.f*y.fy) / yf2,
        (-y.f * ( 2 * x.fx*y.fx + x.f*y.fxx) + x.fxx*yf2 + 2 * x.f*y.fx*y.fx) / yf3,
        (-y.f * ( x.fy*y.fx + x.fx*y.fy + x.f*y.fxy) + x.fxy*yf2 + 2 * x.f*y.fx*y.fy) / yf3,
        (-y.f * ( 2 * x.fy*y.fy + x.f*y.fyy) + x.fyy*yf2 + 2 * x.f*y.fy*y.fy) / yf3,
    };
}

Jet sin(const Jet& x){
    double sinx = std::sin(x.f);
    double cosx = std::cos(x.f);
    return {
        sinx,
        cosx*x.fx,
        cosx*x.fy,
        cosx*x.fxx - sinx*x.fx*x.fx,
        cosx*x.fxy - sinx*x.fx*x.fy,
        cosx*x.fyy - sinx*x.fy*x.fy
    };
}

Jet cos(const Jet& x){
    double sinx = std::sin(x.f);
    double cosx = std::cos(x.f);
    return {
            cosx,
            -sinx*x.fx,
            -sinx*x.fy,
            -cosx*x.fx*x.fx - sinx*x.fxx,
            -cosx*x.fx*x.fy - sinx*x.fxy,
            -cosx*x.fy*x.fy - sinx*x.fyy
    };
}

Jet exp(const Jet& x){
    double e = std::exp(x.f);
    return{
        e,
        x.fx * e,
        x.fy * e,
        e * (x.fx*x.fx + x.fxx),
        e * (x.fx*x.fy + x.fxy),
        e * (x.fy*x.fy + x.fyy)
    };
}

int main(){

    int m;
    std::cout << std::setprecision(15)<<std::fixed;
    std::cin>>m;

    while(m-- > 0){
        double x,y;
        std::cin>>x>>y;
        Jet f(x,1.,0.,0.,0.,0.);
        Jet g(y,0.,1.,0.,0.,0.);
        Jet r = funkcja(f,g);
        std::cout<<r.f<<" "<<r.fx<<+" "<<r.fy<<" "<<r.fxx<<" "<<r.fxy<<" "<<r.fyy<<std::endl;
    }

    return 0;
}