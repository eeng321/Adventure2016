
add_library(utility STATIC utility.cpp)
set_property(TARGET utility PROPERTY CXX_STANDARD 14)
install(TARGETS utility DESTINATION lib)

add_library(dictionary STATIC Dictionary.cpp)
set_property(TARGET dictionary PROPERTY CXX_STANDARD 14)
install(TARGETS dictionary DESTINATION lib)

add_library(command STATIC Command.cpp)
set_property(TARGET command PROPERTY CXX_STANDARD 14)
target_link_libraries(command door)
target_link_libraries(command room)
target_link_libraries(command gameState)
install(TARGETS command DESTINATION lib)