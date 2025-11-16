project(devBlasImpl)


add_library(devblas SHARED
	sgemm.c
)

target_include_directories(devblas PUBLIC ../include/)

install(TARGETS devblas DESTINATION devblas)
