
add_library(playerImpl STATIC Player.cpp)
set_property(TARGET playerImpl PROPERTY CXX_STANDARD 14)
target_link_libraries(playerImpl player)

install(TARGETS playerImpl DESTINATION lib)