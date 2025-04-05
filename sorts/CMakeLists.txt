file(GLOB SORTING_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(sortari STATIC ${SORTING_SOURCES})
target_include_directories(sortari PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
