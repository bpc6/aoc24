add_executable(day01 main.cpp day01.cpp)
target_include_directories(day01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(day01 PRIVATE aoc_lib)

target_compile_definitions(day01 PUBLIC PARENT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")
