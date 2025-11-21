#include "devblas/c_api/blas.h"
#include "devblas/naive_gemm.h"

using namespace devblas;

extern "C" void naive_igemm_ijk(const int *A, const int *B, int *C, int M,
                                int N, int K) {
  internal::naive_gemm_ijk<int>(A, B, C, M, N, K);
}

extern "C" void naive_sgemm_ijk(const float *A, const float *B, float *C, int M,
                                int N, int K) {
  internal::naive_gemm_ijk<float>(A, B, C, M, N, K);
}
