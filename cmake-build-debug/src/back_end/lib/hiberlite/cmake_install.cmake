# Install script for directory: /home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite

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
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/BeanLoader.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/BeanUpdater.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/ChildKiller.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/CppModel.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/Database.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/ModelExtractor.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/Registry.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/SQLiteStmt.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/Visitor.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/bean_ptr.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/common.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/db_error.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/hiberdefs.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/hiberlite.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/nvp.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/shared_res.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/some_types.h"
    "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/back_end/lib/hiberlite/include/sqlite3.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/lib/libhiber.a")
endif()

