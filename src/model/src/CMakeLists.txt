add_library(player player.cpp)
set_property(TARGET player PROPERTY CXX_STANDARD 14)

install(TARGETS player DESTINATION bin)