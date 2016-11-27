SET(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(adventure2016 main.cpp ../../model/include/playerModel.h)
set_property(TARGET adventure2016 PROPERTY CXX_STANDARD 14)


target_link_libraries(adventure2016 userInput)
target_link_libraries(adventure2016 display)
target_link_libraries(adventure2016 ${CURSES_LIBRARIES})
target_link_libraries(adventure2016 restClient)
target_link_libraries(adventure2016 dictionary)
target_link_libraries(adventure2016 command)
target_link_libraries(adventure2016 combat)
target_link_libraries(adventure2016 Threads::Threads)

install(TARGETS adventure2016 DESTINATION bin)