add_subdirectory(lib)
add_subdirectory(tools)
include_directories(include)

install(FILES ${CMAKE_SOURCE_DIR}/include/userInput.h DESTINATION include)
install(FILES ${CMAKE_SOURCE_DIR}/include/display.h DESTINATION include)
