include_directories(include)
add_subdirectory(lib)
add_subdirectory(tools)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
