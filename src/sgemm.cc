#include "devblas/naive_gemm.h"

namespace devblas {
namespace internal {
template <typename T>
  requires(std::integral<T> || std::floating_point<T>)
void naive_gemm_ijk(const T *A, const T *B, T *C, int M, int N, int K) {
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      C[i * N + j] = 0;
      for (int k = 0; k < K; ++k) {
        C[i * N + j] += A[i * K + k] * B[k * N + j];
      }
    }
  }
}

template void naive_gemm_ijk<int>(const int *, const int *, int *, int, int,
                                  int);

template void naive_gemm_ijk<float>(const float *, const float *, float *, int,
                                    int, int);

} // namespace internal
} // namespace devblas
