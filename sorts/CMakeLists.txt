file(GLOB SORTING_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")


foreach(SRC_FILE ${SORTING_SOURCES})
    get_filename_component(SORT_NAME ${SRC_FILE} NAME_WE)
    add_library(${SORT_NAME} STATIC ${SRC_FILE})
    set(SORTING_LIBS ${SORTING_LIBS} ${SORT_NAME})
endforeach()

add_library(sortari INTERFACE)
target_link_libraries(sortari INTERFACE ${SORTING_LIBS})
target_include_directories(sortari INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
