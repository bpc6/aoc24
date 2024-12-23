add_executable(day10 main.cpp day10.cpp)
target_include_directories(day10 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day10 PRIVATE aoc_lib)

target_compile_definitions(day10 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day10_test
        day10_test.cpp
        day10.cpp
)
target_link_libraries(
        day10_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day10_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day10_test)
