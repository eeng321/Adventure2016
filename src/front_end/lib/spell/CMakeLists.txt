add_library(spell STATIC spell.cpp ../../include/spellbook.h)
set_property(TARGET spell PROPERTY CXX_STANDARD 14)

install(TARGETS spell DESTINATION lib)