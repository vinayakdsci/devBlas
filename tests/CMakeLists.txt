# GoogleTest dependency
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(test_gemm
    test_sgemm.cc
)

target_link_libraries(test_gemm
    PRIVATE
    gtest
    gtest_main
    devblas
)

# Register with CTest
add_test(NAME GEMM_TEST COMMAND test_gemm)

