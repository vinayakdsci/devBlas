#ifndef DEVBLAS_C_API_H
#define DEVBLAS_C_API_H

#ifdef __cplusplus
extern "C" {
#endif
void naive_igemm_ijk(const int *, const int *, int *, int, int, int);
void naive_sgemm_ijk(const float *, const float *, float *, int, int, int);
#ifdef __cplusplus
}
#endif

#endif
