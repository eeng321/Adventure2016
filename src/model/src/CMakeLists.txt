
add_library(playerModel playerModel.cpp ../include/itemType.h)
add_library(roomModel roomModel.cpp)
set_property(TARGET roomModel playerModel PROPERTY CXX_STANDARD 14)

install(TARGETS playerModel DESTINATION bin)
install(TARGETS roomModel DESTINATION bin)