add_executable(day13 main.cpp day13.cpp)
target_include_directories(day13 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day13 PRIVATE aoc_lib)

target_compile_definitions(day13 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day13_test
        day13_test.cpp
        day13.cpp
)
target_link_libraries(
        day13_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day13_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day13_test)
