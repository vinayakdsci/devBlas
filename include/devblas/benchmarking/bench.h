#ifndef DEVBLAS_BENCH_H
#define DEVBLAS_BENCH_H

namespace devblas::internal::bench {

template <typename T>
using GemmFn = void (*)(const T *, const T *, T *, int, int, int);

template <typename T>
void benchmark_gemm(const char *name, GemmFn<T> fn, int iters, int M, int N,
                    int K);
} // namespace devblas::internal::bench

#endif
