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
include src/front_end/lib/utility/CMakeFiles/utility.dir/depend.make

# Include the progress variables for this target.
include src/front_end/lib/utility/CMakeFiles/utility.dir/progress.make

# Include the compile flags for this target's objects.
include src/front_end/lib/utility/CMakeFiles/utility.dir/flags.make

src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o: src/front_end/lib/utility/CMakeFiles/utility.dir/flags.make
src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o: ../src/front_end/lib/utility/utility.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utility.dir/utility.cpp.o -c "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/front_end/lib/utility/utility.cpp"

src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utility.dir/utility.cpp.i"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/front_end/lib/utility/utility.cpp" > CMakeFiles/utility.dir/utility.cpp.i

src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utility.dir/utility.cpp.s"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/front_end/lib/utility/utility.cpp" -o CMakeFiles/utility.dir/utility.cpp.s

src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.requires:

.PHONY : src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.requires

src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.provides: src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.requires
	$(MAKE) -f src/front_end/lib/utility/CMakeFiles/utility.dir/build.make src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.provides.build
.PHONY : src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.provides

src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.provides.build: src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o


# Object files for target utility
utility_OBJECTS = \
"CMakeFiles/utility.dir/utility.cpp.o"

# External object files for target utility
utility_EXTERNAL_OBJECTS =

lib/libutility.a: src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o
lib/libutility.a: src/front_end/lib/utility/CMakeFiles/utility.dir/build.make
lib/libutility.a: src/front_end/lib/utility/CMakeFiles/utility.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../lib/libutility.a"
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility" && $(CMAKE_COMMAND) -P CMakeFiles/utility.dir/cmake_clean_target.cmake
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utility.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/front_end/lib/utility/CMakeFiles/utility.dir/build: lib/libutility.a

.PHONY : src/front_end/lib/utility/CMakeFiles/utility.dir/build

src/front_end/lib/utility/CMakeFiles/utility.dir/requires: src/front_end/lib/utility/CMakeFiles/utility.dir/utility.cpp.o.requires

.PHONY : src/front_end/lib/utility/CMakeFiles/utility.dir/requires

src/front_end/lib/utility/CMakeFiles/utility.dir/clean:
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility" && $(CMAKE_COMMAND) -P CMakeFiles/utility.dir/cmake_clean.cmake
.PHONY : src/front_end/lib/utility/CMakeFiles/utility.dir/clean

src/front_end/lib/utility/CMakeFiles/utility.dir/depend:
	cd "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/src/front_end/lib/utility" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility" "/home/jmedwid/Dropbox/Current Classes/CMPT 373/Project/adventure2016/cmake-build-debug/src/front_end/lib/utility/CMakeFiles/utility.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/front_end/lib/utility/CMakeFiles/utility.dir/depend

