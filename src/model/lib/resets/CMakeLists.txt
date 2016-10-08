add_library(resets STATIC resets.cpp)
set_property(TARGET resets PROPERTY CXX_STANDARD 14)

install(TARGETS resets DESTINATION lib)
