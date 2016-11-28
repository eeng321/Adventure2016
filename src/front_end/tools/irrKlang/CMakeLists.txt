include_directories(include)


file(GLOB HEADER_FILES "include/*.h")
install(FILES ${HEADER_FILES} DESTINATION include)