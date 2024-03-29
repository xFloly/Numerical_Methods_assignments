# Numerical Methods Assignments Repository

Welcome to the Numerical Methods Assignments Repository! This repository contains my solutions to assignments from my university course on numerical methods. Each assignment corresponds to a specific numerical method or technique covered in the course. Below is a brief overview of each assignment along with the implemented solutions.

## Assignments

1. **Ex02 - Secant and Bisection**
   - **Theme**: Secant and Bisection methods for root finding.
   - **Solution**: Concise implementations (secant and bisection) along with a wrapper function (findZero) for selecting the method based on function value signs. Iterative refinement ensures convergence to the specified tolerance.

2. **Ex03 - Newton**
   - **Theme**: Implementation of the Newton method for finding roots of a given function.
   - **Solution**: The code contains implementations of functions for finding curves, surfaces, and fixed points using the Newton method. It utilizes the Newton method for iterative refinement until convergence to find roots efficiently.

3. **Ex04 - Scaled Gauss**
   - **Theme**: Implementation of the Scaled Gauss method for solving systems of linear equations with scaling.
   - **Solution**: The code presents an implementation of the Scaled Gauss method, which involves scaling the rows of the coefficient matrix to improve numerical stability. It includes functions for swapping rows, solving equations, and calculating residuals. The main function solveEquations utilizes Scaled Gauss along with iterative refinement to find the solution vector with a specified accuracy.

4. **Ex05 - Jets**
   - **Theme**: Implementation of automatic differentiation for jet propulsion calculations, utilizing the Jet struct to compute derivatives.
   - **Solution**: The provided code demonstrates automatic differentiation using the Jet struct to compute derivatives of a given function.

5. **Ex06 - SOR (Successive Over-Relaxation)**
   - **Theme**: Implementation of the Successive Over-Relaxation (SOR) method for efficiently solving linear systems of equations..
   - **Solution**: The function iteratively updates the solution vector using SOR until convergence or a specified number of iterations..

6. **Ex07 - Hermit Interpolation**
   - **Theme**: Implementation of Hermit interpolation method for approximating functions from a set of given data points.
   - **Solution**: The code includes a Hermit interpolation function that computes the coefficients and efficiently handles repeated data points and computes the polynomial coefficients accordingly.

7. **Ex08 - Spline**
   - **Theme**: Implementation of a cubic spline interpolation method for smooth curve fitting through a set of given points.
   - **Solution**: The code implements a cubic spline interpolation algorithm to generate a smooth curve passing through the specified data points. It computes the coefficients at any given point.
