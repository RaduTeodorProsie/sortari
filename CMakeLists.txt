cmake_minimum_required(VERSION 3.12)  # TBB::tbb requires CMake ≥3.12
project(sortari)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(TBB REQUIRED)  # Find TBB

add_executable(main main.cpp)
add_subdirectory(sorts)     # Assuming "sorts" defines the "sortari" library

# Link libraries to the executable
target_link_libraries(main PRIVATE
    sortari      # Your custom library from "sorts"
    TBB::tbb     # Use double colon for TBB target
)
