#include "devblas/c_api/blas.h"
#include <assert.h>
#include <stdio.h>

int main() {
  int A[4] = {1, 0, 1, 0};
  int B[4] = {1, 0, 1, 0};
  int C[4] = {0, 0, 0, 0};

  naive_igemm_ijk(A, B, C, 2, 2, 2);

  bench_igemm(naive_igemm_ijk, 3, 1024, 1024, 1024);
  bench_sgemm(naive_sgemm_ijk, 3, 1024, 1024, 1024);

  assert(C[0] == 1 && C[1] == 0 && C[2] == 1 && C[3] == 0 &&
         "Numerical mismatch");

  fprintf(stdout, "Passed the test!\n");
}
