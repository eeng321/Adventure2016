include_directories (include)
add_subdirectory (src)
add_subdirectory (lib)


install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
