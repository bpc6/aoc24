add_executable(day12 main.cpp day12.cpp)
target_include_directories(day12 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day12 PRIVATE aoc_lib)

target_compile_definitions(day12 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day12_test
        day12_test.cpp
        day12.cpp
)
target_link_libraries(
        day12_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day12_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day12_test)
