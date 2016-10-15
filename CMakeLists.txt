cmake_minimum_required (VERSION 3.2)

project (adventure2016)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/hiberlite/src)


add_subdirectory(src)
