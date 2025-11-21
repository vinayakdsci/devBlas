#include "devblas/c_api/blas.h"
#include "devblas/benchmarking/bench.h"
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

extern "C" void bench_igemm(devblas_naive_igemm_fn fn, int iter, int M, int N,
                            int K) {
  internal::bench::benchmark_gemm<int>("default_naive_igemm", fn, iter, M, N,
                                       K);
}

extern "C" void bench_sgemm(devblas_naive_sgemm_fn fn, int iter, int M, int N,
                            int K) {
  internal::bench::benchmark_gemm<float>("default_naive_sgemm", fn, iter, M, N,
                                         K);
}
