#ifndef DEVBLAS_BENCHMARK_UTILS_H
#define DEVBLAS_BENCHMARK_UTILS_H

#include <chrono>

namespace devblas::internal {
namespace bench {
struct Timer {
  Timer() : start_(std::chrono::steady_clock::now()) {}
  double elapsed_ms() {
    using namespace std::literals;
    auto now = std::chrono::steady_clock::now();
    return (double)((now - start_) / 1ns) * (double)1e-6;
  }

private:
  std::chrono::time_point<std::chrono::steady_clock> start_;
};

} // namespace bench
} // namespace devblas::internal

#endif
