# Install script for directory: /home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/id/cmake_install.cmake")
  include("/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/door/cmake_install.cmake")
  include("/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/room/cmake_install.cmake")
  include("/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item/cmake_install.cmake")
  include("/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/resets/cmake_install.cmake")
  include("/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/npc/cmake_install.cmake")

endif()

