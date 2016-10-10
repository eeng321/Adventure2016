add_executable(rest_server restServer.cpp playerEndpoint.cpp)
target_link_libraries(rest_server net_static)

set_property(TARGET rest_server PROPERTY CXX_STANDARD 14)
