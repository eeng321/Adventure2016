add_library(room STATIC room.cpp )
set_property(TARGET room PROPERTY CXX_STANDARD 14)
target_link_libraries(room door)
install(TARGETS room DESTINATION lib)
