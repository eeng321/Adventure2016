add_library(playerModel playerModel.cpp ../include/id.h)
set_property(TARGET playerModel PROPERTY CXX_STANDARD 14)

install(TARGETS playerModel DESTINATION bin)