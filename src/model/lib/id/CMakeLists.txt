add_library(id STATIC id.cpp)
set_property(TARGET id PROPERTY CXX_STANDARD 14)

install(TARGETS id DESTINATION lib)
