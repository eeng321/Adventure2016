include_directories (include)
add_subdirectory (src)
add_subdirectory (lib)


install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
