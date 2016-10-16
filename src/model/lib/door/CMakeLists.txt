add_library(door STATIC door.cpp)
set_property(TARGET door PROPERTY CXX_STANDARD 14)

install(TARGETS door DESTINATION lib)
