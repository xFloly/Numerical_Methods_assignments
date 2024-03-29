//Filip Soszynski
#include <iostream>
#include "vectalg.h"


void swap(double& a, double& b){
    double tmp = a;
    a = b;
    b = tmp;
}

void swapRows(Matrix & M, int i, int j){
    if( i == j) return;
    if(j >= M.size() || i >= M.size()){
        return;
    }
    for(int k = 0; k < M.size(); k++){
        double tmp = M(i,k);
        M(i,k) = M(j,k);
        M(j,k) = tmp;
    }
}

Vector solveEquations( const Matrix & initA, const Vector & initb, double  eps){
    Matrix A(initA);
    Vector b(initb);
    Vector x(A.size());
    for(int i = 0; i < x.size(); i++){
        x[i] = 0.;
    }
    Vector norm(A.size());
    for(int i = 0; i < A.size(); i++){
        double max = A(i,0);
        for(int j = 1; j < A.size(); j++){
            if(A(i,j) > max){
                max = A(i,j);
            }
        }
        norm[i] = max;
    }
    for(int k = 0; k < A.size(); k++){
        double val = std::abs(A(k, k)/ norm[k]);
        int index = k;
        for(int i = k+1; i < A.size(); i++){
            double z = std::abs(A(i, k) / norm[k]);
            if(z > val){
                val = z;
                index = i;
            }
        }
        swapRows(A, index, k);
        swap(b[index], b[k]);
        //gauss
        for(int i = k + 1; i < A.size(); i++){
            double z = A(i, k)/ A(k, k);
            A(i,k) = 0.;
            for(int j = k+1; j < A.size(); j++){
                A(i, j) -= z * A(k, j) ;
            }
            b[i] -= z * b[k];
        }
    }
    //solution
    for(int i = A.size()-1; i >= 0; i--){
        double s = b[i];
        for(int j = i + 1;j < A.size(); j++){
            s -= A(i,j)*x[j];
        }
        x[i] = s/ A(i,i);
    }
    for(int i = 0; i < 100; i++){
        Vector r = residual_vector(initA, initb, x);
        if(r.max_norm() < eps) return x;
        //Ae = r
        Vector e = solveEquations(initA,r,eps);
        for(int i = 0; i < A.size(); i++){
            x[i] += e[i];
        }
    }
    return x;
}