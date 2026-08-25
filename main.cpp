#include "generate_random_matrix.h"
#include "matrix_multiply.h"
#include <mpi.h>

int main(int argc, char *argv[]){

    int rows = 5;
    int columns = 3;

    std::vector<std::vector<double>> rand_mat(rows, std::vector<double>(columns, -1.1));
    std::vector<double> rand_vec(columns, 0.);
    std::vector<double> rand_vec_local(columns, 0.);
    std::vector<double> multiplication_result(rows, 0.);

    // OMP Code
    /*
    generate_matrix(rand_mat);

    generate_vector(rand_vec);

    matrix_vector_multiply(rand_mat, rand_vec, multiplication_result);
    */

    // MPI code

    MPI_Init(&argc, &argv);
    
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    generate_matrix_mpi(rand_mat, world_size, world_rank);

    generate_vector_mpi(rand_vec_local, world_size, world_rank);
    MPI_Allreduce(rand_vec_local.data(), rand_vec.data(), columns,
    MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    std::vector<int> indices;
    int indices_per_rank = rows / world_size;
    if (world_rank != world_size-1){
        for (int i=world_rank*indices_per_rank; i<(world_rank+1)*indices_per_rank; i++){
            indices.push_back(i);
        }
    }
    else {
        for (int i=world_rank*indices_per_rank; i<rows; i++){
            indices.push_back(i);
        }
    }

    for (int i=0; i<indices.size(); i++){
        std::cout << world_rank << indices[i] << std::endl;
    }

    matrix_vector_multiply_mpi(rand_mat, rand_vec, multiplication_result, indices);

    

    MPI_Finalize();

    return 0;

}