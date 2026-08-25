#include <iostream>
#include <omp.h>
#include <bits/stdc++.h>

#ifndef MAT_MUL
#define MAT_MUL

// OMP Code
// void matrix_vector_multiply(std::vector<std::vector<double>>& A,
//     std::vector<double>& x, std::vector<double>& b);

// MPI Code
void matrix_vector_multiply_mpi(std::vector<std::vector<double>>& A,
    std::vector<double>& x, std::vector<double>& b, const std::vector<int>& indices);

#endif