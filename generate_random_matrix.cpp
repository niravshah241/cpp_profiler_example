#include "generate_random_matrix.h"

//OMP Code
/*
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

*/


// MPI Rank
void generate_matrix_mpi(std::vector<std::vector<double>>& A, int size, int rank){
    int rows = A.size();
    int columns = A[0].size();
    std::vector<int> indices;
    int indices_per_rank = rows / size;
    if (rank != size-1){
        for (int i=rank*indices_per_rank; i<(rank+1)*indices_per_rank; i++){
            indices.push_back(i);
        }
    }
    else {
        for (int i=rank*indices_per_rank; i<rows; i++){
            indices.push_back(i);
        }
    }

    for (int i=0; i<indices.size(); i++){
        for (int j=0; j<columns; j++){
            A[indices[i]][j] = rand() % 100;
        }
    }
        
}

void generate_vector_mpi(std::vector<double>& x, int size, int rank){
    int rows = x.size();
    std::vector<int> indices;
    int indices_per_rank = rows / size;
    if (rank != size-1){
        for (int i=rank*indices_per_rank; i<(rank+1)*indices_per_rank; i++){
            indices.push_back(i);
        }
    }
    else {
        for (int i=rank*indices_per_rank; i<rows; i++){
            indices.push_back(i);
        }
    }

    for (int i=0; i<indices.size(); i++){
            x[indices[i]] = rand() % 100;
    }
}