add_subdirectory(lib)
add_subdirectory(tools)

install(FILES ${CMAKE_SOURCE_DIR}/include/userInput.h DESTINATION include)
install(FILES ${CMAKE_SOURCE_DIR}/include/ncursesAdventure.h DESTINATION include)