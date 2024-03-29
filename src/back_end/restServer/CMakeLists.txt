
# attempt to find static library first if this is set; snippet from supercollider
set(YAMLCPP_STATIC_LIBRARY TRUE)
if(YAMLCPP_STATIC_LIBRARY)
    set(YAMLCPP_STATIC libyaml-cpp.a)
endif()

# find the yaml-cpp include directory
find_path(YAMLCPP_INCLUDE_DIR yaml-cpp/yaml.h
        PATH_SUFFIXES include
        PATHS
        ~/Library/Frameworks/yaml-cpp/include/
        /Library/Frameworks/yaml-cpp/include/
        /usr/local/include/
        /usr/include/
        /sw/yaml-cpp/         # Fink
        /opt/local/yaml-cpp/  # DarwinPorts
        /opt/csw/yaml-cpp/    # Blastwave
        /opt/yaml-cpp/
        ${YAMLCPP_DIR}/include/)

# find the yaml-cpp library
find_library(YAMLCPP_LIBRARY
        NAMES ${YAMLCPP_STATIC} yaml-cpp
        PATH_SUFFIXES lib64 lib
        PATHS ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw
        /opt/local
        /opt/csw
        /opt
        ${YAMLCPP_DIR}/lib)

add_library(parser STATIC parser.cpp)
set_property(TARGET parser PROPERTY CXX_STANDARD 14)
install(TARGETS parser DESTINATION lib)

add_library(etljob STATIC etlJob.cpp)
set_property(TARGET etljob PROPERTY CXX_STANDARD 14)
install(TARGETS etljob DESTINATION lib)

file(COPY midgaard.yml DESTINATION ${PROJECT_BINARY_DIR}/bin)
file(COPY world.yaml DESTINATION ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(parser room)

add_executable(testex test.cpp)
target_link_libraries(testex parser yaml-cpp playerModel roomModel door )
set_target_properties(testex PROPERTIES COMPILE_FLAGS "-std=c++14")

add_executable(rest_server restServer.cpp playerEndpoint.cpp playerDriver.cpp chatEndpoint.cpp roomEndpoint.cpp roomDriver.cpp npcEndpoint.cpp npcDriver.cpp itemEndpoint.cpp itemDriver.cpp credential.cpp initializeDB.cpp)
target_link_libraries(rest_server net_static hiber ${CMAKE_DL_LIBS} playerModel npcModel roomModel itemModel door parser yaml-cpp etljob)

set_target_properties(rest_server PROPERTIES COMPILE_FLAGS "-std=c++14")

set_target_properties(rest_server PROPERTIES COMPILE_FLAGS "-lyaml-cpp")



# handle the QUIETLY and REQUIRED arguments and set YAMLCPP_FOUND to TRUE if all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(YAMLCPP DEFAULT_MSG YAMLCPP_INCLUDE_DIR YAMLCPP_LIBRARY)
mark_as_advanced(YAMLCPP_INCLUDE_DIR YAMLCPP_LIBRARY)

set_property(TARGET rest_server PROPERTY CXX_STANDARD 14)
