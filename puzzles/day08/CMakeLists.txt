add_executable(day08 main.cpp day08.cpp)
target_include_directories(day08 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day08 PRIVATE aoc_lib)

target_compile_definitions(day08 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day08_test
        day08_test.cpp
        day08.cpp
)
target_link_libraries(
        day08_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day08_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day08_test)
