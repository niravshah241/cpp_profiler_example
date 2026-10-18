# Score-P simplified

This repository is aimed at introducing simple example usage of [Score-P](https://www.vi-hps.org/projects/score-p/overview/overview.html). We introduce example of elementwise Matrix-Vector multiplication and its parallelization using for loop. Two examples are introduced here:

- OpenMP parallelization in the folder ``omp_code``: Parallelization is performed using ``pragma omp parallel for``
- MPI parallelization in the folder ``mpi_code``: Parallelization is performed by dividing Matrix row indices across all ranks

Each example contains parallelization of matrix along row where each process/thread performs multiplication of Matrix rows assigned to it with a given vector. Broadly each code is structured as follow:

- Generate Vector and Matrix
- Fill Vector and Matrix with random numbers
- Perform elementwise Matrix-Vector multiplication

### Installation

Instructions to run the examples presented are given in the blog [Score-P Simplified: Introduction and Installation](https://medium.com/@niravshahcolab/score-p-simplified-introduction-and-installation-f786d7bf6892).

## Disclaimer

In downloading this SOFTWARE you are deemed to have read and agreed to
the following terms: This SOFT- WARE has been designed with an exclusive
focus on civil applications. It is not to be used for any illegal,
deceptive, misleading or unethical purpose or in any military
applications. This includes ANY APPLICATION WHERE THE USE OF THE
SOFTWARE MAY RESULT IN DEATH, PERSONAL INJURY OR SEVERE PHYSICAL OR
ENVIRONMENTAL DAMAGE. Any redistribution of the software must retain
this disclaimer. BY INSTALLING, COPYING, OR OTHERWISE USING THE
SOFTWARE, YOU AGREE TO THE TERMS ABOVE. IF YOU DO NOT AGREE TO THESE
TERMS, DO NOT INSTALL OR USE THE SOFTWARE.
