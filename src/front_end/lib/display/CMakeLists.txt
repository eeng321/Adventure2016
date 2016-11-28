add_library(display STATIC display.cpp)
set_property(TARGET display PROPERTY CXX_STANDARD 14)
target_link_libraries(display piglatin)

install(TARGETS display DESTINATION lib)
