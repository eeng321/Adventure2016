add_library(playerModel playerModel.cpp)
add_library(roomModel roomModel.cpp)
set_property(TARGET roomModel PROPERTY CXX_STANDARD 14)
set_property(TARGET playerModel PROPERTY CXX_STANDARD 14)

install(TARGETS playerModel DESTINATION bin)
install(TARGETS roomModel DESTINATION bin)