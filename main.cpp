#include "generate_random_matrix.h"
#include "matrix_multiply.h"

int main(){

    int rows = 10;
    int columns = 8;

    std::vector<std::vector<double>> rand_mat(rows, std::vector<double>(columns));
    std::vector<double> rand_vec(columns);
    std::vector<double> multiplication_result(rows);

    generate_matrix(rand_mat);

    generate_vector(rand_vec);

    matrix_vector_multiply(rand_mat, rand_vec, multiplication_result);

    return 0;

}