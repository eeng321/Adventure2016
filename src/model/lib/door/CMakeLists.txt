add_library(door STATIC doorModel.cpp)
set_property(TARGET door PROPERTY CXX_STANDARD 14)
target_link_libraries(door id)
install(TARGETS door DESTINATION lib)
