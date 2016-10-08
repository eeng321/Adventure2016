
add_library(controller STATIC Controller.cpp)
set_property(TARGET controller PROPERTY CXX_STANDARD 14)
target_link_libraries(controller player)

install(TARGETS controller DESTINATION lib)