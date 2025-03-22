add_executable(day15 main.cpp day15.cpp)
target_include_directories(day15 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day15 PRIVATE aoc_lib)

target_compile_definitions(day15 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day15_test
        day15_test.cpp
        day15.cpp
)
target_link_libraries(
        day15_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day15_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day15_test)
