#include "generate_random_matrix_mpi.h"

void get_indices(std::vector<int>& indices, const int rows, const int size, const int rank){
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

}

void generate_matrix_mpi(std::vector<std::vector<double>>& A, const int size, const int rank){
    int rows = A.size();
    int columns = A[0].size();
    std::vector<int> indices;

    get_indices(indices, rows, size, rank);

    for (int i=0; i<indices.size(); i++){
        for (int j=0; j<columns; j++){
            A[indices[i]][j] = rand() % 100;
        }
    }
        
}

void generate_vector_mpi(std::vector<double>& x, const int size, const int rank){
    int rows = x.size();
    std::vector<int> indices;

    get_indices(indices, rows, size, rank);

    for (int i=0; i<indices.size(); i++){
            x[indices[i]] = rand() % 100;
    }
}