#include <iostream>
#include <mpi.h>



int main(int argc, char *argv[]){


int size;
int rank;

MPI_Init(&argc, &argv);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

for (int i=rank; i<10; i=i+size){

	        std::cout << "Hello World." << " My rank: " << rank
			                << " , Iteration: " << i << "." << std::endl;
}

MPI_Finalize();

return 0;

}
