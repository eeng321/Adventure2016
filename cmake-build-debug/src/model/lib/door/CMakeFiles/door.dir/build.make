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
CMAKE_COMMAND = /home/william/clion-2016.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/william/clion-2016.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/william/cmpt373/adventure2016

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/william/cmpt373/adventure2016/cmake-build-debug

# Include any dependencies generated for this target.
include src/model/lib/door/CMakeFiles/door.dir/depend.make

# Include the progress variables for this target.
include src/model/lib/door/CMakeFiles/door.dir/progress.make

# Include the compile flags for this target's objects.
include src/model/lib/door/CMakeFiles/door.dir/flags.make

src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o: src/model/lib/door/CMakeFiles/door.dir/flags.make
src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o: ../src/model/lib/door/doorModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/william/cmpt373/adventure2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/door.dir/doorModel.cpp.o -c /home/william/cmpt373/adventure2016/src/model/lib/door/doorModel.cpp

src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/door.dir/doorModel.cpp.i"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/william/cmpt373/adventure2016/src/model/lib/door/doorModel.cpp > CMakeFiles/door.dir/doorModel.cpp.i

src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/door.dir/doorModel.cpp.s"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/william/cmpt373/adventure2016/src/model/lib/door/doorModel.cpp -o CMakeFiles/door.dir/doorModel.cpp.s

src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.requires:

.PHONY : src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.requires

src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.provides: src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.requires
	$(MAKE) -f src/model/lib/door/CMakeFiles/door.dir/build.make src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.provides.build
.PHONY : src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.provides

src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.provides.build: src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o


# Object files for target door
door_OBJECTS = \
"CMakeFiles/door.dir/doorModel.cpp.o"

# External object files for target door
door_EXTERNAL_OBJECTS =

lib/libdoor.a: src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o
lib/libdoor.a: src/model/lib/door/CMakeFiles/door.dir/build.make
lib/libdoor.a: src/model/lib/door/CMakeFiles/door.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/william/cmpt373/adventure2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../lib/libdoor.a"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door && $(CMAKE_COMMAND) -P CMakeFiles/door.dir/cmake_clean_target.cmake
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/door.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/model/lib/door/CMakeFiles/door.dir/build: lib/libdoor.a

.PHONY : src/model/lib/door/CMakeFiles/door.dir/build

src/model/lib/door/CMakeFiles/door.dir/requires: src/model/lib/door/CMakeFiles/door.dir/doorModel.cpp.o.requires

.PHONY : src/model/lib/door/CMakeFiles/door.dir/requires

src/model/lib/door/CMakeFiles/door.dir/clean:
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door && $(CMAKE_COMMAND) -P CMakeFiles/door.dir/cmake_clean.cmake
.PHONY : src/model/lib/door/CMakeFiles/door.dir/clean

src/model/lib/door/CMakeFiles/door.dir/depend:
	cd /home/william/cmpt373/adventure2016/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/william/cmpt373/adventure2016 /home/william/cmpt373/adventure2016/src/model/lib/door /home/william/cmpt373/adventure2016/cmake-build-debug /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/door/CMakeFiles/door.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/model/lib/door/CMakeFiles/door.dir/depend

