add_executable(day11 main.cpp day11.cpp)
target_include_directories(day11 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day11 PRIVATE aoc_lib)

target_compile_definitions(day11 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day11_test
        day11_test.cpp
        day11.cpp
)
target_link_libraries(
        day11_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day11_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day11_test)
