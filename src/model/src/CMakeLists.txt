add_library(playerModel playerModel.cpp)
set_property(TARGET playerModel PROPERTY CXX_STANDARD 14)

install(TARGETS playerModel DESTINATION bin)