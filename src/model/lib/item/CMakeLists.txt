add_library(item STATIC item.cpp)
set_property(TARGET item PROPERTY CXX_STANDARD 14)
target_link_libraries(item itemModel)

install(TARGETS item DESTINATION lib)
