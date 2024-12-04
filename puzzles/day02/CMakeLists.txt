add_executable(day02 main.cpp day02.cpp)
target_include_directories(day02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day02 PRIVATE aoc_lib)

target_compile_definitions(day02 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day02_test
        day02_test.cpp
        day02.cpp
)
target_link_libraries(
        day02_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day02_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day02_test)
