#include "devblas/benchmarking/utils.h"
#include <iostream>
#include <random>

namespace devblas::internal {
namespace bench {

template <typename T>
using GemmFn = void (*)(const T *, const T *, T *, int, int, int);

template <typename T>
void benchmark_gemm(const char *name, GemmFn<T> fn, int iters, int M, int N,
                    int K) {
  std::mt19937 rng(0);
  std::uniform_real_distribution<float> dist(-1.f, 1.f);

  std::vector<T> A = std::vector<T>(M * K);
  std::vector<T> B = std::vector<T>(K * N);
  std::vector<T> C = std::vector<T>(M * N);

  for (int64_t i = 0; i < M * K; ++i) {
    A[i] = static_cast<T>(dist(rng));
  }

  for (int64_t i = 0; i < K * N; ++i) {
    B[i] = static_cast<T>(dist(rng));
  }

  double numOps = 2.0 * M * N * K;
  std::vector<double> times;

  for (int i = 0; i < iters; ++i) {
    Timer t = Timer();
    fn(A.data(), B.data(), C.data(), M, N, K);
    times.push_back((t.elapsed_ms() * (double)1e-3));
  }

  double gflops = 0.f;
  for (const double &elapsed : times) {
    auto gflop = (numOps / elapsed) * (double)1e-9;
    gflops += gflop;
  }

  std::cout << name << ":\n";
  std::cout << "\tTotal GFLOP/s " << gflops << "\n";
  std::cout << "\tAverage GFLOP/s: " << gflops / (double)iters << "\n";
}

template void benchmark_gemm<int>(const char *name, GemmFn<int>, int iters,
                                  int M, int N, int K);
template void benchmark_gemm<float>(const char *name, GemmFn<float>, int iters,
                                    int M, int N, int K);

} // namespace bench
} // namespace devblas::internal
