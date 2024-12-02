add_library(aoc_lib parsing.cpp)
target_include_directories(aoc_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
        utils_test
        test_parsing.cpp
)
target_link_libraries(
        utils_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(utils_test)
