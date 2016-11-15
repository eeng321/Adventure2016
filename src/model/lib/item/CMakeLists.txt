add_library(itemModel STATIC item.cpp itemModel.cpp)
set_property(TARGET itemModel PROPERTY CXX_STANDARD 14)

install(TARGETS itemModel DESTINATION bin)