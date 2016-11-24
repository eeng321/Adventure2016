add_library(spell STATIC spell.cpp spellbook.cpp)
set_property(TARGET spell PROPERTY CXX_STANDARD 14)

install(TARGETS spell DESTINATION lib)