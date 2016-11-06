
add_library(controller STATIC Controller.cpp)
set_property(TARGET controller PROPERTY CXX_STANDARD 14)

target_link_libraries(controller player)
target_link_libraries(controller id)
target_link_libraries(controller restClient)
target_link_libraries(controller utility)
target_link_libraries(controller parser)
target_link_libraries(controller yaml-cpp)
install(TARGETS controller DESTINATION lib)