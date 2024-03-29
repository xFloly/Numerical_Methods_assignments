//Filip Soszynski
#include <iostream>
#include <vector>
#include <iomanip>

std::vector<double> SOR(std::vector<std::vector<double>> diagonal, std::vector<double> b, std::vector<double> x, int M, double w, double L, double N){
    for(int iter = 0; iter < L; iter++) {
        for (int i = 0; i < N; i++) {
            auto s = b[i];

            for(int j = 1; j <= M; j++){
                if(M-j < 0 || i-j < 0) break;
                s -= diagonal[M-j][i-j]*x[i-j];
            }

            for(int j = 1; j <= M; j++){
                if(diagonal[M-j].size() <= i) break;
                s -= diagonal[M-j][i]*x[i+j];
            }

            x[i] = (1 - w) * x[i] + w * s / diagonal[M][i];
        }
    }
    return x;
}

 int N = 14;

int main() {
    int A[N];
    int B[N+2];
    int sum = 0;
    int tmp = 0;
    for(int i = 1; i < N; i++){
        B[i] = A[i-1] + A[i - ]
    }


    return 0;
}
