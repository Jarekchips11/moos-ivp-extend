# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaroslawlewandowski/moos-ivp-extend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaroslawlewandowski/moos-ivp-extend/build

# Include any dependencies generated for this target.
include src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/depend.make

# Include the progress variables for this target.
include src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/progress.make

# Include the compile flags for this target's objects.
include src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/flags.make

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.o: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/flags.make
src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.o: ../src/pPatrolPoint/PatrolPoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaroslawlewandowski/moos-ivp-extend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.o"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.o -c /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/PatrolPoint.cpp

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.i"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/PatrolPoint.cpp > CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.i

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.s"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/PatrolPoint.cpp -o CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.s

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.o: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/flags.make
src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.o: ../src/pPatrolPoint/PatrolPoint_Info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaroslawlewandowski/moos-ivp-extend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.o"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.o -c /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/PatrolPoint_Info.cpp

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.i"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/PatrolPoint_Info.cpp > CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.i

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.s"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/PatrolPoint_Info.cpp -o CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.s

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/main.cpp.o: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/flags.make
src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/main.cpp.o: ../src/pPatrolPoint/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaroslawlewandowski/moos-ivp-extend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/main.cpp.o"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pPatrolPoint.dir/main.cpp.o -c /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/main.cpp

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pPatrolPoint.dir/main.cpp.i"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/main.cpp > CMakeFiles/pPatrolPoint.dir/main.cpp.i

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pPatrolPoint.dir/main.cpp.s"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint/main.cpp -o CMakeFiles/pPatrolPoint.dir/main.cpp.s

# Object files for target pPatrolPoint
pPatrolPoint_OBJECTS = \
"CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.o" \
"CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.o" \
"CMakeFiles/pPatrolPoint.dir/main.cpp.o"

# External object files for target pPatrolPoint
pPatrolPoint_EXTERNAL_OBJECTS =

../bin/pPatrolPoint: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint.cpp.o
../bin/pPatrolPoint: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/PatrolPoint_Info.cpp.o
../bin/pPatrolPoint: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/main.cpp.o
../bin/pPatrolPoint: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/build.make
../bin/pPatrolPoint: /Users/jaroslawlewandowski/moos-ivp/build/MOOS/MOOSCore/lib/libMOOS.a
../bin/pPatrolPoint: src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaroslawlewandowski/moos-ivp-extend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../bin/pPatrolPoint"
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pPatrolPoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/build: ../bin/pPatrolPoint

.PHONY : src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/build

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/clean:
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint && $(CMAKE_COMMAND) -P CMakeFiles/pPatrolPoint.dir/cmake_clean.cmake
.PHONY : src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/clean

src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/depend:
	cd /Users/jaroslawlewandowski/moos-ivp-extend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaroslawlewandowski/moos-ivp-extend /Users/jaroslawlewandowski/moos-ivp-extend/src/pPatrolPoint /Users/jaroslawlewandowski/moos-ivp-extend/build /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint /Users/jaroslawlewandowski/moos-ivp-extend/build/src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pPatrolPoint/CMakeFiles/pPatrolPoint.dir/depend
