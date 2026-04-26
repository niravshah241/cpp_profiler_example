#include <iostream>
#include "omp.h"
#include <bits/stdc++.h>

#ifndef MAT_MUL
#define MAT_MUL

void matrix_vector_multiply(std::vector<std::vector<double>>& A,
    std::vector<double>& x, std::vector<double>& b);

#endif