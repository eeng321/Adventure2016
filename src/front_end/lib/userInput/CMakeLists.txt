
add_library(userInput STATIC userInput.cpp)
set_property(TARGET userInput PROPERTY CXX_STANDARD 14)

install(TARGETS userInput DESTINATION lib)