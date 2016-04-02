project(sw-base)

cmake_minimum_required(VERSION 2.4.0)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -fPIC -O2")

message("compile options: ${CMAKE_CXX_FLAGS}")
 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB PROJECT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/*/*.cpp")

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

#Install static lib.
install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib)

#Install headers.
set(HEADER_PATH "sw/base")
file(GLOB SUB_SOURCE_DIRS "${PROJECT_SOURCE_DIR}/*")
foreach(SUB_SOURCE_DIR ${SUB_SOURCE_DIRS})
    file(GLOB SUB_HEADERS "${SUB_SOURCE_DIR}/*.h" "${SUB_SOURCE_DIR}/*.hpp")
    get_filename_component(SUB_LIB_NAME ${SUB_SOURCE_DIR} NAME)
    install(FILES ${SUB_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${HEADER_PATH}/${SUB_LIB_NAME})
endforeach(SUB_SOURCE_DIR)
