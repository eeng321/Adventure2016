
add_library(utility STATIC utility.cpp)
set_property(TARGET utility PROPERTY CXX_STANDARD 14)

install(TARGETS utility DESTINATION lib)