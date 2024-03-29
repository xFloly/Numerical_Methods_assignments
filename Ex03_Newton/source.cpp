//Filip Soszynski

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

static const long double epsilon = pow(10.,-14.);
static const double delta = pow(10.,-6.);

typedef void (*FuncPointer)(const double* x, double* y, double* Df);

void printVector(const double* x, unsigned N){
    for(unsigned i=0;i<N;++i)
        printf("%17.17f ",x[i]);
    printf("\n");
}
bool Kramer(double* J, double* M, double*F, int n){
    if(n == 6){
        if(std::abs(F[0])  <= epsilon && std::abs(F[1]) <= epsilon ) return true;
        double D = J[0] * J[4] - J[1] * J[3];
        double Dx = F[0] * J[4] - F[1] * J[1];
        double Dy = J[0] * F[1] - J[3] * F[0];
        //if(std::abs(  Dx / D ) < delta  &&  std::abs(  Dy / D ) < delta) return true;
        M[0] -= Dx / D;
        M[1] -= Dy / D;
    }
    if(n == 8){
        double G[2];
        G[0] = F[0] - M[0];
        G[1] = F[1] - M[1];
        if(std::abs(G[0]) <= epsilon && std::abs(G[1]) <= epsilon ) return true;
        double Dg[4];
        Dg[0] = J[0] - 1;
        Dg[1] = J[1];
        Dg[2] = J[4];
        Dg[3] = J[5] - 1;
        double D = Dg[0] * Dg[3] - Dg[1] * Dg[2];
        double Dx = G[0] * Dg[3] - G[1] * Dg[1];
        double Dy = Dg[0] * G[1] - Dg[2] * G[0];
        //if(std::abs(  Dx / D ) < delta  &&  std::abs(  Dy / D ) < delta) return true;
        M[0] -= Dx / D;
        M[1] -= Dy / D;
    }
    return false;
}
bool Njuton(FuncPointer f,double* J, double* M, double* F, int n){
    f(M,F,J);
    return Kramer(J,M,F,n);
}

int findCurve(FuncPointer f, double* x, unsigned k, double h){
    double F[2];
    double J[6];
    double M[3];
    int j = 1;
    M[0] = x[0];
    M[1] = x[1];
    while(j <= k){
        M[2] = x[2]+j*h;
        int l = 0;
        while(l < 100){
            if(Njuton(f,J,M,F,6)) break;
            l++;
        }
        if (l == 100 ){
            return j;
        }
        printVector(M,3);
        j++;
    }
    return 0;
}

int findSurface(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2){
    double F[1];
    double J[3];
    double M[3];
    int j = 1;
    M[0] = x[0];
    while(j <= k1) {
        int i = 1;
        M[1] = x[1]+j*h1;
        while (i <= k2) {
            M[2] = x[2]+i*h2;
            int l = 0;
            while(l < 100){
                f(M,F,J);
                if(std::abs(F[0]) <= epsilon){
                    break;
                }
                M[0] -= F[0]/J[0];
                l++;
            }
            if(l == 100){
                return j*k1 + i;
            }
            printVector(M, 3);
            i++;
        }
        j++;
        std::cout<<std::endl;
    }
    return 0;
}

int findFixedPoints(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2){
    double F[2];
    double J[8];
    double M[4];
    int j = 1;
            M[0] = x[0];
            M[1] = x[1];
    while(j <= k1) {
            M[2] = x[2]+j*h1;
        int i = 1;
        while (i <= k2) {
            M[3] = x[3]+i*h2;
            int l = 0;
            while(l < 1000){
                if(Njuton(f,J,M,F,8))break;
                l++;
            }
            if(l == 1000){
                return j*k1 + i;
            }
            printVector(M, 4);
            i++;
        }
        j++;
        std::cout<<std::endl;
    }
    return 0;
}