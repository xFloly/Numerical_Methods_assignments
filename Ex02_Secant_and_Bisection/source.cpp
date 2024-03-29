//Filip Soszynski
#include <iostream>
#include <cmath>

double secant(double (*f)(double), double a, double b, double fa, double fb, int M, double eps, double delta);
double bisection(double (*f)(double), double a, double b, double fa, double fb, int M, double eps, double delta);
double sgn(double x);

double sgn(double x) {
    if (x >= 0.0)
        return 1.0;
    return -1.0;
}

double secant(double (*f)(double), double a, double b, double fa, double fb, int M, double eps, double delta) {
    double c, fc;
    if(fa == 0) {
        return a;
    }
    if(fb == 0) {
        return b;
    }
    for (int k = 1; k <= M; k++) {
        if(fb == 0 || a==b) {
            return b;
        }
        c = b - (fb*(b-a))/(fb-fa);
        fc = f(c);
        a = b;
        fa = fb;
        b = c;
        fb = fc;
    }
    return c;
}

double bisection(double (*f)(double), double a, double b, double fa, double fb, int M, double eps, double delta) {
    double e = b - a;
    double c = 0.0, fc;
    for (int k = 1; k <= M; k++) {
        e = e / 2.0;
        c = a + e;
        fc = f(c);
        if(fc==0){
            return c;
        }
        if (sgn(fc) != sgn(fa)) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        if(fabs(e) < 0.1){
            return secant(*f,a,b,fa,fb,M-k+1,eps,delta);
        }
    }
    return c;
}

double findZero(
        double (*f)(double),  // funkcja której zera szukamy w [a, b]
        double a,             // lewy koniec przedziału
        double b,             // prawy koniec przedziału
        int M,                // maksymalna dozwolona liczba wywołań funkcji f
        double eps,           // spodziewana dokładność zera
        double delta          // wystarczający błąd bezwzględny wyniku
) {
    double fa = f(a), fb = f(b);
    if(fa == 0) {
        return a;
    }
    if(fb == 0) {
        return b;
    }
    if(sgn(fa) != sgn(fb)){
        return bisection(*f,a,b,fa,fb,M-2,eps,delta);
    }
    return secant(*f,a,b,fa,fb,M-2,eps,delta);
}
