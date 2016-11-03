add_library(room STATIC room.cpp )
set_property(TARGET room PROPERTY CXX_STANDARD 14)

install(TARGETS room DESTINATION lib)
