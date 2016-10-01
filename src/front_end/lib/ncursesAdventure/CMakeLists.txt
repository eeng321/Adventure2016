add_library(ncursesAdventure STATIC ncursesAdventure.cpp)
set_property(TARGET ncursesAdventure PROPERTY CXX_STANDARD 14)

install(TARGETS ncursesAdventure DESTINATION lib)
