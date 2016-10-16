add_library(npc STATIC npc.cpp)
set_property(TARGET npc PROPERTY CXX_STANDARD 14)

install(TARGETS npc DESTINATION lib)
