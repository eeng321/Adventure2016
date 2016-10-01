add_library(restClient STATIC RestClient.cpp)

target_link_libraries(restClient net_static)
set_property(TARGET restClient PROPERTY CXX_STANDARD 14)

install(TARGETS restClient DESTINATION lib)