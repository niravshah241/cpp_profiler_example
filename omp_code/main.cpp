#include "generate_random_matrix_omp.h"
#include "matrix_multiply_omp.h"

int main(int argc, char *argv[]){

    int rows = std::stoi(argv[1]);
    int columns = std::stoi(argv[2]);

    std::vector<std::vector<double>> rand_mat(rows, std::vector<double>(columns, -1.1));
    std::vector<double> rand_vec(columns, 0.);
    std::vector<double> rand_vec_local(columns, 0.);
    std::vector<double> multiplication_result(rows, 0.);

    generate_matrix(rand_mat);

    generate_vector(rand_vec);

    matrix_vector_multiply(rand_mat, rand_vec, multiplication_result);
       
    return 0;

}