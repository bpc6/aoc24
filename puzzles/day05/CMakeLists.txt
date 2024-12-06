add_executable(day05 main.cpp day05.cpp)
target_include_directories(day05 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day05 PRIVATE aoc_lib)

target_compile_definitions(day05 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day05_test
        day05_test.cpp
        day05.cpp
)
target_link_libraries(
        day05_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day05_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day05_test)
