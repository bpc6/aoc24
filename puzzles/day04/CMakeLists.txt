add_executable(day04 main.cpp day04.cpp)
target_include_directories(day04 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day04 PRIVATE aoc_lib)

target_compile_definitions(day04 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day04_test
        day04_test.cpp
        day04.cpp
)
target_link_libraries(
        day04_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day04_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day04_test)
