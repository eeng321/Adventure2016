include_directories(include)

# controller depends on this
add_subdirectory(lib/player)

add_subdirectory(lib)
add_subdirectory(tools)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
