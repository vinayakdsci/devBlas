#ifndef DEVBLAS_SGEMM_H
#define DEVBLAS_SGEMM_H

#include <concepts>

namespace devblas {
namespace internal {

template <typename T>
  requires(std::integral<T> || std::floating_point<T>)
void naive_gemm_ijk(const T *A, const T *B, T *C, int M, int N, int K);

}
} // namespace devblas
#endif
