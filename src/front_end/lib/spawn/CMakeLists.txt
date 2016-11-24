add_library(spawn STATIC spawn.cpp)
set_property(TARGET spawn PROPERTY CXX_STANDARD 14)

install(TARGETS spawn DESTINATION lib)