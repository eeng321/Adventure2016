add_executable(rest_server restServer.cpp playerEndpoint.cpp)
target_link_libraries(rest_server net_static)
target_link_libraries(rest_server yaml-cpp)

find_package(yaml-cpp REQUIRED)
add_executable(parser parser.cpp)
include_directories(${YAML_CPP_SOURCE_DIR}/include)
target_link_libraries(parser yaml-cpp)
target_compile_options(parser PRIVATE -lyaml-cpp)



set_target_properties(parser PROPERTIES COMPILE_FLAGS "-std=c++11")

set_property(TARGET rest_server PROPERTY CXX_STANDARD 14)
