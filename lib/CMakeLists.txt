add_library(
        aoc_lib
        aocmath.cpp
        parsing.cpp
        grid.cpp
)
target_include_directories(aoc_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(aoc_lib PUBLIC Eigen3::Eigen)

add_executable(
        utils_test
        aocmath_test.cpp
        parsing_test.cpp
        grid_test.cpp
)
target_link_libraries(
        utils_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(utils_test)
