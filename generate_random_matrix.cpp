#include "generate_random_matrix.h"

void generate_matrix(std::vector<std::vector<double>>& A){
    int rows = A.size();
    int columns = A[0].size();

    #pragma omp parallel for
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            A[i][j] = rand() % 100;
        }
    }

}

void generate_vector(std::vector<double>& x){
    int columns = x.size();

    #pragma omp parallel for
    for (int j=0; j<columns; j++){
        x[j] = rand() % 100;
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
    }

}