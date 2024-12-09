add_executable(day06 main.cpp day06.cpp)
target_include_directories(day06 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day06 PRIVATE aoc_lib)

target_compile_definitions(day06 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day06_test
        day06_test.cpp
        day06.cpp
)
target_link_libraries(
        day06_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day06_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day06_test)
