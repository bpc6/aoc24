add_executable(day09 main.cpp day09.cpp)
target_include_directories(day09 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day09 PRIVATE aoc_lib)

target_compile_definitions(day09 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day09_test
        day09_test.cpp
        day09.cpp
)
target_link_libraries(
        day09_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day09_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day09_test)
