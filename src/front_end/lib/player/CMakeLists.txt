
add_library(player STATIC Player.cpp)
set_property(TARGET player PROPERTY CXX_STANDARD 14)
target_link_libraries(player playerModel)

install(TARGETS player DESTINATION lib)