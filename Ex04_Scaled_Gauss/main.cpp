#include "source.cpp"
#include <iostream>
#include "vectalg.h"
using namespace std;

// Sebastian Musial
#include "vectalg.h"

Vector solveEquations(const Matrix &A0, const Vector &b, double eps)
{
    const std::size_t n = A0.size();
    Vector permutation(n);
    Vector scale(n);
    Matrix C(A0);
    Vector x(n);
    Vector b0(b);
    for (int i = 0; i < n; i++)
    {
        double maxi{A0(i, 0)};
        for (int j = 1; j < n; j++)
        {
            maxi = std::max(maxi, std::abs(A0(i, j)));
        }
        scale[i] = maxi;
    }
    for (int i = 0; i < n; i++)
    {
        permutation[i] = i;
    }

    for (int k = 0; k < n - 1; k++)
    {
        int j{k};
        for (int i = k; i < n; i++)
        {
            // wybieramy element glowny dla ktorego abs(a[i,k])/scale[i] jest najwieksze
            if (std::abs(C(permutation[j], k)) / scale[permutation[j]] <= std::abs(C(permutation[i], k)) / scale[permutation[i]])
            {
                j = i;
            }
        }
        double t{permutation[k]};
        permutation[k] = permutation[j];
        permutation[j] = t;
        for (int i = k + 1; i < n; i++)
        {
            double z = C(permutation[i], k) / C(permutation[k], k);
            C(permutation[i], k) = 0.;
            for (int j = k + 1; j < n; j++)
            {
                C(permutation[i], j) = C(permutation[i], j) - z * C(permutation[k], j);
            }
            b0[permutation[i]] = b0[permutation[i]] - z * b0[permutation[k]];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        double sum{};
        for (int j = i + 1; j < n; j++)
        {
            sum += C(permutation[i], j) * x[j];
        }
        x[i] = (b0[permutation[i]] - sum) / C(permutation[i], i);
    }

    Vector rk = residual_vector(A0, b, x);
    if (std::abs(rk.max_norm()) < eps)
    {
        return x;
    }
    Vector ek(n);
    ek = solveEquations(A0, rk, eps);
    for (int i = 0; i < n; i++)
    {
        x[i] = x[i] + ek[i];
    }

    return x;
}