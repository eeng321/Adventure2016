
add_executable(rest_server restServer.cpp playerEndpoint.cpp)
target_link_libraries(rest_server net_static hiber ${CMAKE_DL_LIBS} player)
target_link_libraries(rest_server yaml-cpp)

set_property(TARGET rest_server PROPERTY CXX_STANDARD 14)
