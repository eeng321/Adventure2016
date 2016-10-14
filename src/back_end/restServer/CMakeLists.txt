find_package(yaml-cpp REQUIRED)
add_executable(rest_server restServer.cpp playerEndpoint.cpp parser.cpp)
target_link_libraries(rest_server net_static)
target_link_libraries(rest_server yaml-cpp)
set_target_properties(rest_server PROPERTIES COMPILE_FLAGS "-std=c++14")
set_target_properties(rest_server PROPERTIES COMPILE_FLAGS "-lyaml-cpp")

set_property(TARGET rest_server PROPERTY CXX_STANDARD 11)
