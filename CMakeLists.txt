cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# /usr/local/lib64/libbenchmark.a
link_libraries(pthread benchmark)

include(CTest)
enable_testing()

add_subdirectory(functional_programming)
add_subdirectory(move_forward)
add_subdirectory(performance-test)
add_subdirectory(error_handling)
add_subdirectory(reversing)
add_subdirectory(memory_test)
add_subdirectory(capture)
add_subdirectory(typecast)
add_subdirectory(thread)
add_executable(testv main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
