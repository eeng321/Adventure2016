cmake_minimum_required (VERSION 2.8.7)

include_directories (include)
file(GLOB HEADER_FILES "include/*.h")

include_directories (src)

file(GLOB HEADER_FILES "include/*.h")
install(FILES ${HEADER_FILES} DESTINATION include)

file (GLOB HIBERLITE_SOURCE_FILES "src/*.cpp" "src/*.c")

set(SOURCE_FILES
    ${HIBERLITE_SOURCE_FILES}
)

add_library(hiber ${SOURCE_FILES})
install(TARGETS hiber DESTINATION lib)