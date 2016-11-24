# Install script for directory: /home/william/cmpt373/adventure2016/src/back_end/lib/pistache

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/async.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/client.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/common.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/cookie.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/description.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/endpoint.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/flags.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/http.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/http_defs.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/http_header.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/http_headers.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/iterator_adapter.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/listener.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/mailbox.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/mime.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/net.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/optional.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/os.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/peer.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/prototype.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/reactor.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/router.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/stream.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/tcp.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/timer_pool.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/transport.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/typeid.h"
    "/home/william/cmpt373/adventure2016/src/back_end/lib/pistache/include/view.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/william/cmpt373/adventure2016/cmake-build-debug/src/back_end/lib/pistache/src/cmake_install.cmake")

endif()

