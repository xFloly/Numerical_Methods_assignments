#include "source.h"
#include <iostream>
#include <cmath>
using namespace std;

double wielomian(double x){ 	return (((x-6)*x+11)*x)-6;	}
double wielomianSinExp(double x)
{	return ((((x-6)*x+11)*x)-4 + sin(15*x))*exp(-x*x);	}
double kwadrat(double x){	return (x*x-2);	 }
double kwadrat100(double x){  return 1e100*(x*x-2);	}
double kwadrat_10(double x){ 	return 1e-10*(x*x-2);	}

int main(){
    cout.precision(17);                                               // Spodziewany wynik
    cout << findZero(wielomian, 0, 4, 20, 1e-15, 1e-14) << "       "<< "1 lub 2 lub 3" << endl;
    cout << findZero(wielomian, 0, 40, 20, 1e-15, 1e-14) <<"       "<<"1 lub 2 lub 3" << endl;
    cout << findZero(wielomian, 1, 2, 2, 1e-15, 1e-14) << "       "<< "1 lub 2" << endl;
    cout << findZero(wielomian, -150, 1.9, 20, 1e-15, 1e-14) << "       "<< 1 << endl;
    cout << findZero(wielomian, 1.5, 2.99, 20, 1e-15, 1e-14) << "       "<< 2 << endl;
    cout << findZero(wielomian, 2.01, 40, 20, 1e-15, 1e-14) << "       "<< 3 << endl;
    cout << findZero(wielomian, 1.5, 6, 20, 1e-15, 1e-14) << "       "<< "1 lub 2 lub 3" << endl;

    cout << findZero(wielomianSinExp, -1, 3, 60, 1e-60, 1e-14) << "       "<< 0.43636925909804245 << endl;
    cout << findZero(wielomianSinExp, -3, 3, 60, 1e-160, 1e-14) << "       "<<0.43636925909804245 << endl;

    cout << findZero(kwadrat, 0, 4, 15, 1e-11, 1e-14) << "       "<<1.414213562373095 << endl;
    cout << findZero(kwadrat100, 0, 4, 15, 1e-11, 1e-14) << "       "<<1.414213562373095 << endl;
    cout << findZero(kwadrat_10, 0, 4, 10, 1e-10, 1e-14) << "       "<<"kazdy punkt z przedzialu [1, 1.73205]" << endl;
    cout << findZero(kwadrat_10, 0, 4, 15, 1e-160, 1e-14) <<"       "<<1.414213562373095 << endl;
    return 0;
}
