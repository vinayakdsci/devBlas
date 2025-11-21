#ifndef DEVBLAS_C_API_H
#define DEVBLAS_C_API_H

#ifdef __cplusplus
extern "C" {
#endif
void naive_igemm_ijk(const int *, const int *, int *, int, int, int);
void naive_sgemm_ijk(const float *, const float *, float *, int, int, int);
typedef void (*devblas_naive_sgemm_fn)(const float *, const float *, float *,
                                       int, int, int);
typedef void (*devblas_naive_igemm_fn)(const int *, const int *, int *, int,
                                       int, int);

void bench_igemm(devblas_naive_igemm_fn fn, int iter, int M, int N, int K);
void bench_sgemm(devblas_naive_sgemm_fn fn, int iter, int M, int N, int K);
#ifdef __cplusplus
}
#endif

#endif
