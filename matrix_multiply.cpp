#include "matrix_multiply.h"

void matrix_vector_multiply(std::vector<std::vector<double>>& A,
    std::vector<double>& x, std::vector<double>& b){
        int rows = A.size();
        int columns = A[0].size();
        
        #pragma omp parallel for
        for (int i=0; i<rows; i++){
            int sum = 0;
            for (int j=0; j<columns; j++){
                sum += A[i][j] * b[j]; 
            }
            b[i] = sum;
        }

    }
