
add_library(gameState STATIC GameState.cpp)
set_property(TARGET gameState PROPERTY CXX_STANDARD 14)

target_link_libraries(gameState player)
target_link_libraries(gameState id)
target_link_libraries(gameState utility)
install(TARGETS gameState DESTINATION lib)