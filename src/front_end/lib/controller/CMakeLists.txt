
add_library(controller STATIC Controller.cpp)
set_property(TARGET controller PROPERTY CXX_STANDARD 14)

target_link_libraries(controller playerImpl)
target_link_libraries(controller restClient)
target_link_libraries(controller utility)
install(TARGETS controller DESTINATION lib)