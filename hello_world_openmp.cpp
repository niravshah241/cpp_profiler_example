#include <omp.h>
#include <iostream>

int main(){

#pragma omp parallel for
	for (int i=0; i<23; i++)
	{
		int tid = omp_get_thread_num();
		int nthreads = omp_get_num_threads();

		std::cout << "Hello World from Thread " << tid 
			<< " of threads " << nthreads << " iteration: " << i << 
			"." << std::endl;
	}


return 0;

}