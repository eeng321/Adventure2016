SET(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(adventure2016 main.cpp)
set_property(TARGET adventure2016 PROPERTY CXX_STANDARD 14)

target_link_libraries(adventure2016 ${CURSES_LIBRARIES})
target_link_libraries(adventure2016 userInput)

install(TARGETS adventure2016 DESTINATION bin)