add_library(piglatin STATIC piglatin.cpp)
set_property(TARGET piglatin PROPERTY CXX_STANDARD 14)

install(TARGETS piglatin DESTINATION lib)