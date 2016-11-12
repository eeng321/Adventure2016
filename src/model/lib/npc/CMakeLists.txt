add_library(npcModel STATIC npc.cpp npcModel.cpp)
set_property(TARGET npcModel PROPERTY CXX_STANDARD 14)

install(TARGETS npcModel DESTINATION bin)
