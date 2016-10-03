add_library(display STATIC display.cpp)
set_property(TARGET display PROPERTY CXX_STANDARD 14)

install(TARGETS display DESTINATION lib)
