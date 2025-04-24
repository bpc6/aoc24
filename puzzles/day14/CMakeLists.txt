add_executable(day14 main.cpp day14.cpp bot_env.cpp multi_bot_env.cpp)
target_include_directories(day14 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day14 PRIVATE aoc_lib)

target_compile_definitions(day14 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_executable(
        day14_test
        day14_test.cpp
        day14.cpp
        bot_env_test.cpp
        bot_env.cpp
        multi_bot_env_test.cpp
        multi_bot_env.cpp
)
target_link_libraries(
        day14_test
        aoc_lib
        GTest::gtest_main
        GTest::gmock_main
)
target_compile_definitions(day14_test PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

include(GoogleTest)
gtest_discover_tests(day14_test)
