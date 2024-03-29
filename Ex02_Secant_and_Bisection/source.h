#ifndef BACA2_SOURCE_H
#define BACA2_SOURCE_H

#include <iostream>

double findZero(
        double (*f)(double),  // funkcja której zera szukamy w [a, b]
        double a,             // lewy koniec przedziału
        double b,             // prawy koniec przedziału
        int M,                // maksymalna dozwolona liczba wywołań funkcji f
        double eps,           // spodziewana dokładność zera
        double delta          // wystarczający błąd bezwzględny wyniku
);


#endif
