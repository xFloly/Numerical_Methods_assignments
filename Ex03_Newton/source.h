#ifndef BACA03_SOURCE_H
#define BACA03_SOURCE_H
typedef void (*FuncPointer)(const double* x, double* y, double* Df);
int findCurve(FuncPointer f, double* x, unsigned k, double h);
int findSurface(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2);
int findFixedPoints(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2);

#endif
