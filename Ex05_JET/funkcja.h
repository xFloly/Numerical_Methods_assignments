#ifndef BACA05_FUNKCJA_H
#define BACA05_FUNKCJA_H

#include <iostream>


template <typename T>
T funkcja(const T & x, const T & y){
    T w = sin(x*x - 2*(y+1))/exp(-y*y+cos(x*y));
    return w;
}


#endif
