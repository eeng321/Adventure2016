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
include src/model/lib/npc/CMakeFiles/npcModel.dir/depend.make

# Include the progress variables for this target.
include src/model/lib/npc/CMakeFiles/npcModel.dir/progress.make

# Include the compile flags for this target's objects.
include src/model/lib/npc/CMakeFiles/npcModel.dir/flags.make

src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o: src/model/lib/npc/CMakeFiles/npcModel.dir/flags.make
src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o: ../src/model/lib/npc/npc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/william/cmpt373/adventure2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/npcModel.dir/npc.cpp.o -c /home/william/cmpt373/adventure2016/src/model/lib/npc/npc.cpp

src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/npcModel.dir/npc.cpp.i"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/william/cmpt373/adventure2016/src/model/lib/npc/npc.cpp > CMakeFiles/npcModel.dir/npc.cpp.i

src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/npcModel.dir/npc.cpp.s"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/william/cmpt373/adventure2016/src/model/lib/npc/npc.cpp -o CMakeFiles/npcModel.dir/npc.cpp.s

src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.requires:

.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.requires

src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.provides: src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.requires
	$(MAKE) -f src/model/lib/npc/CMakeFiles/npcModel.dir/build.make src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.provides.build
.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.provides

src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.provides.build: src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o


src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o: src/model/lib/npc/CMakeFiles/npcModel.dir/flags.make
src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o: ../src/model/lib/npc/npcModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/william/cmpt373/adventure2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/npcModel.dir/npcModel.cpp.o -c /home/william/cmpt373/adventure2016/src/model/lib/npc/npcModel.cpp

src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/npcModel.dir/npcModel.cpp.i"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/william/cmpt373/adventure2016/src/model/lib/npc/npcModel.cpp > CMakeFiles/npcModel.dir/npcModel.cpp.i

src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/npcModel.dir/npcModel.cpp.s"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/william/cmpt373/adventure2016/src/model/lib/npc/npcModel.cpp -o CMakeFiles/npcModel.dir/npcModel.cpp.s

src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.requires:

.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.requires

src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.provides: src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.requires
	$(MAKE) -f src/model/lib/npc/CMakeFiles/npcModel.dir/build.make src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.provides.build
.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.provides

src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.provides.build: src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o


# Object files for target npcModel
npcModel_OBJECTS = \
"CMakeFiles/npcModel.dir/npc.cpp.o" \
"CMakeFiles/npcModel.dir/npcModel.cpp.o"

# External object files for target npcModel
npcModel_EXTERNAL_OBJECTS =

lib/libnpcModel.a: src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o
lib/libnpcModel.a: src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o
lib/libnpcModel.a: src/model/lib/npc/CMakeFiles/npcModel.dir/build.make
lib/libnpcModel.a: src/model/lib/npc/CMakeFiles/npcModel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/william/cmpt373/adventure2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../../../lib/libnpcModel.a"
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && $(CMAKE_COMMAND) -P CMakeFiles/npcModel.dir/cmake_clean_target.cmake
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/npcModel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/model/lib/npc/CMakeFiles/npcModel.dir/build: lib/libnpcModel.a

.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/build

src/model/lib/npc/CMakeFiles/npcModel.dir/requires: src/model/lib/npc/CMakeFiles/npcModel.dir/npc.cpp.o.requires
src/model/lib/npc/CMakeFiles/npcModel.dir/requires: src/model/lib/npc/CMakeFiles/npcModel.dir/npcModel.cpp.o.requires

.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/requires

src/model/lib/npc/CMakeFiles/npcModel.dir/clean:
	cd /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc && $(CMAKE_COMMAND) -P CMakeFiles/npcModel.dir/cmake_clean.cmake
.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/clean

src/model/lib/npc/CMakeFiles/npcModel.dir/depend:
	cd /home/william/cmpt373/adventure2016/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/william/cmpt373/adventure2016 /home/william/cmpt373/adventure2016/src/model/lib/npc /home/william/cmpt373/adventure2016/cmake-build-debug /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc /home/william/cmpt373/adventure2016/cmake-build-debug/src/model/lib/npc/CMakeFiles/npcModel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/model/lib/npc/CMakeFiles/npcModel.dir/depend

