
add_library(userInput STATIC userInput.cpp)
set_property(TARGET userInput PROPERTY CXX_STANDARD 14)
target_link_libraries(userInput controller)
target_link_libraries(userInput spawn)

install(TARGETS userInput DESTINATION lib)