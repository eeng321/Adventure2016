SET(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(irrKlang)

file(COPY midgaard.ogg DESTINATION ${PROJECT_BINARY_DIR}/bin)
file(COPY smurf.ogg DESTINATION ${PROJECT_BINARY_DIR}/bin)

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
target_link_libraries(adventure2016 spawn)
target_link_libraries(adventure2016 spell)
target_link_libraries(adventure2016 Threads::Threads)
target_link_libraries(adventure2016 ${PROJECT_SOURCE_DIR}/src/front_end/tools/irrKlang/bin/libIrrKlang.so)

install(TARGETS adventure2016 DESTINATION bin)