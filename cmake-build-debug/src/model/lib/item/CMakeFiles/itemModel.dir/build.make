# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/jmedwid/clion-2016.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jmedwid/clion-2016.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug"

# Include any dependencies generated for this target.
include src/model/lib/item/CMakeFiles/itemModel.dir/depend.make

# Include the progress variables for this target.
include src/model/lib/item/CMakeFiles/itemModel.dir/progress.make

# Include the compile flags for this target's objects.
include src/model/lib/item/CMakeFiles/itemModel.dir/flags.make

src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o: src/model/lib/item/CMakeFiles/itemModel.dir/flags.make
src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o: ../src/model/lib/item/item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/itemModel.dir/item.cpp.o -c "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib/item/item.cpp"

src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itemModel.dir/item.cpp.i"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib/item/item.cpp" > CMakeFiles/itemModel.dir/item.cpp.i

src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itemModel.dir/item.cpp.s"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib/item/item.cpp" -o CMakeFiles/itemModel.dir/item.cpp.s

src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.requires:

.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.requires

src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.provides: src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.requires
	$(MAKE) -f src/model/lib/item/CMakeFiles/itemModel.dir/build.make src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.provides.build
.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.provides

src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.provides.build: src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o


src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o: src/model/lib/item/CMakeFiles/itemModel.dir/flags.make
src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o: ../src/model/lib/item/itemModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/itemModel.dir/itemModel.cpp.o -c "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib/item/itemModel.cpp"

src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itemModel.dir/itemModel.cpp.i"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib/item/itemModel.cpp" > CMakeFiles/itemModel.dir/itemModel.cpp.i

src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itemModel.dir/itemModel.cpp.s"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib/item/itemModel.cpp" -o CMakeFiles/itemModel.dir/itemModel.cpp.s

src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.requires:

.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.requires

src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.provides: src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.requires
	$(MAKE) -f src/model/lib/item/CMakeFiles/itemModel.dir/build.make src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.provides.build
.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.provides

src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.provides.build: src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o


# Object files for target itemModel
itemModel_OBJECTS = \
"CMakeFiles/itemModel.dir/item.cpp.o" \
"CMakeFiles/itemModel.dir/itemModel.cpp.o"

# External object files for target itemModel
itemModel_EXTERNAL_OBJECTS =

lib/libitemModel.a: src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o
lib/libitemModel.a: src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o
lib/libitemModel.a: src/model/lib/item/CMakeFiles/itemModel.dir/build.make
lib/libitemModel.a: src/model/lib/item/CMakeFiles/itemModel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../../../lib/libitemModel.a"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && $(CMAKE_COMMAND) -P CMakeFiles/itemModel.dir/cmake_clean_target.cmake
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/itemModel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/model/lib/item/CMakeFiles/itemModel.dir/build: lib/libitemModel.a

.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/build

src/model/lib/item/CMakeFiles/itemModel.dir/requires: src/model/lib/item/CMakeFiles/itemModel.dir/item.cpp.o.requires
src/model/lib/item/CMakeFiles/itemModel.dir/requires: src/model/lib/item/CMakeFiles/itemModel.dir/itemModel.cpp.o.requires

.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/requires

src/model/lib/item/CMakeFiles/itemModel.dir/clean:
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" && $(CMAKE_COMMAND) -P CMakeFiles/itemModel.dir/cmake_clean.cmake
.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/clean

src/model/lib/item/CMakeFiles/itemModel.dir/depend:
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/model/lib/item" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/model/lib/item/CMakeFiles/itemModel.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/model/lib/item/CMakeFiles/itemModel.dir/depend

