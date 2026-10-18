#include "matrix_multiply_mpi.h"

void matrix_vector_multiply_mpi(std::vector<std::vector<double>>& A,
    std::vector<double>& x, std::vector<double>& b, const std::vector<int>& indices){
        for (int i=0; i<indices.size(); i++){
            int sum = 0;
            for (int j=0; j<A[0].size(); j++){
                sum += A[indices[i]][j] * x[j];
            }
            b[i] = sum;
        }
    }