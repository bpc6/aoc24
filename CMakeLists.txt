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

# Add subdirectories for each puzzle
add_subdirectory(lib)
add_subdirectory(puzzles/day01)
add_subdirectory(puzzles/day02)
