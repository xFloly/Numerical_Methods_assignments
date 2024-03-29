//Filip Soszynski
#include <iostream>
#include <vector>
#include <cmath>


long double horner(std::vector<long double> polynomial,std::vector<long double> x, long double z){
    int n = polynomial.size();
    long double result = polynomial[0];
    for (int i=1; i < n; i++){
        long double product = 1.;
        for(int j = 0; j < i; j++){
            product *= z-x[j];
        }
        product *= polynomial[i];
        result += product;
    }
    return result;
}

std::vector<long double> hermit(std::vector<long double> x, std::vector<long double> y){
    int N = x.size();

    std::vector<std::vector<long double>> function(1);
    {
        int k = 0;
        for (int i = 0; i < N; i++) {
            int j = 0;
            int div = 1;
            std::vector<long double> point(1);
            point[j] = y[i];
            while (x[i] == x[i+1]) {
                point.resize(point.size() + 1);
                point[++j] = y[++i];
                div *= j;
                point[j] /= div;
            }

            function[k++] = point;
            function.resize(function.size() + 1);
        }
        function.resize(function.size() - 1);
    }

    std::vector<long double> fx(N);
    {
        int k = 0;
        for (auto &v: function) {
            for (int i = 0; i < v.size(); i++) //x fx | f' f''
                fx[k++] = v[0];
        }
    }

    std::vector<long double> polynomial(N);
    std::vector<long double> next(N-1);


    {
        int k = 0;
        for (int j = 0; j < N-1; j++) {

            polynomial[k++] = fx[0];

            for(int a = 0; a < next.size(); a++) {
                for (auto & b : function) {
                    for(int c = 0; c < b.size(); c++){
                        if(b.size() > j + 1 && c < b.size() - j - 1){
                            next[a++] = b[j + 1];
                            if(a == next.size()) break;
                        } else {
                            next[a++] = NAN;
                            if(a == next.size()) break;
                        }
                    }
                    if(a == next.size()) break;
                }
            }


            for (int i = 0; i < next.size() ; i++) {
                if(std::isnan(next[i])) {
                    next[i] = (fx[i + 1] - fx[i]) / (x[i + 1 + j] - x[i]);
                }
            }

            fx = std::vector<long double>(next);
            next.resize(fx.size()-1);

        }
        polynomial[k] = fx[0];
    }

    return polynomial;
}




int main(int argc, char **argv){
    std::cout.precision(15);
    std::cout << std::fixed;

    int M, N;
    std::cin>>M>>N;
    std::vector<long double> x(M);
    std::vector<long double> y(M);
    std::vector<long double> solve(N);

    for(int i = 0; i < M; i++){
        std::cin>>x[i];
    }

    for (int i = 0; i < M; i++) {
        std::cin >> y[i];
    }

    for(int i = 0; i < N; i++){
        std::cin >> solve[i];
    }

    std::vector<long double> polynomial = hermit(x,y);

    for(int i = 0; i < M; i++){
        std::cout<<polynomial[i]<<" ";
    }
    std::cout<<std::endl;

    for(int i = 0; i < N; i++) {
        std::cout << horner(polynomial,x, solve[i]) << " ";
    }
}
/**

5 1
1.0 1.0 2.0 2.0 2.0
2.0 3.0 6.0 7.0 8.0
4.0

*/