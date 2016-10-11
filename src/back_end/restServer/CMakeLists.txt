add_executable(rest_server restServer.cpp playerEndpoint.cpp)
target_link_libraries(rest_server net_static)
target_link_libraries(rest_server yaml-cpp)


add_executable(parser parser.cpp)
target_link_libraries(parser yaml-cpp)
set_target_properties(parser PROPERTIES COMPILE_FLAGS "-std=c++11")

set_property(TARGET rest_server PROPERTY CXX_STANDARD 14)
