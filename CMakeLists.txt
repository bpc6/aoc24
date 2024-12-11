cmake_minimum_required(VERSION 3.26)
project(aoc24)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# Add Google Test using FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/35d0c365609296fa4730d62057c487e3cfa030ff.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Fetch Eigen
FetchContent_Declare(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG        3.4.0
)
set(BUILD_TESTING OFF)
set(EIGEN_BUILD_TESTING OFF)
set(EIGEN_MPL2_ONLY ON)
set(EIGEN_BUILD_PKGCONFIG OFF)
set(EIGEN_BUILD_DOC OFF)
FetchContent_MakeAvailable(eigen)

# Add subdirectories for each puzzle
add_subdirectory(lib)
add_subdirectory(puzzles/day01)
add_subdirectory(puzzles/day02)
add_subdirectory(puzzles/day03)
add_subdirectory(puzzles/day04)
add_subdirectory(puzzles/day05)
add_subdirectory(puzzles/day06)
add_subdirectory(puzzles/day07)
add_subdirectory(puzzles/day08)
add_subdirectory(puzzles/day09)
