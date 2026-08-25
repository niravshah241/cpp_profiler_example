#include "matrix_multiply.h"

// OMP code
/*
void matrix_vector_multiply(std::vector<std::vector<double>>& A,
    std::vector<double>& x, std::vector<double>& b){
        int rows = A.size();
        int columns = A[0].size();
        
        #pragma omp parallel for
        for (int i=0; i<rows; i++){
            int sum = 0;
            for (int j=0; j<columns; j++){
                sum += A[i][j] * x[j]; 
            }
            b[i] = sum;
        }
    }

*/


// MPI Code
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