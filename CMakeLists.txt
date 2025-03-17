cmake_minimum_required(VERSION 3.1)
project(sortari)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)
add_subdirectory(sorts)
target_link_libraries(main PRIVATE sortari)