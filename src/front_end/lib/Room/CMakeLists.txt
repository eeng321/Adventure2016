
add_library(room STATIC Room.cpp)
set_property(TARGET room PROPERTY CXX_STANDARD 14)
target_link_libraries(room roomModel)

install(TARGETS room DESTINATION lib)