add_executable(day03 main.cpp day03.cpp)
target_include_directories(day03 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day03 PRIVATE aoc_lib)

target_compile_definitions(day03 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day03_test
        day03_test.cpp
        day03.cpp
)
target_link_libraries(
        day03_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day03_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day03_test)
