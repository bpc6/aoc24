add_executable(day07 main.cpp day07.cpp)
target_include_directories(day07 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day07 PRIVATE aoc_lib)

target_compile_definitions(day07 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day07_test
        day07_test.cpp
        day07.cpp
)
target_link_libraries(
        day07_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day07_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day07_test)
