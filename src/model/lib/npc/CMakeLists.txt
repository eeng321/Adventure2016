add_library(npcModel STATIC npcModel.cpp)
set_property(TARGET npcModel PROPERTY CXX_STANDARD 14)

install(TARGETS npcModel DESTINATION lib)
