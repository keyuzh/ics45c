# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ics45c/projects/exercise1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ics45c/projects/exercise1/out

# Include any dependencies generated for this target.
include CMakeFiles/ics45cprojectproblems.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ics45cprojectproblems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ics45cprojectproblems.dir/flags.make

CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.o: CMakeFiles/ics45cprojectproblems.dir/flags.make
CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.o: ../problems/problem3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/exercise1/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.o -c /home/ics45c/projects/exercise1/problems/problem3.cpp

CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/exercise1/problems/problem3.cpp > CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.i

CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/exercise1/problems/problem3.cpp -o CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.s

# Object files for target ics45cprojectproblems
ics45cprojectproblems_OBJECTS = \
"CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.o"

# External object files for target ics45cprojectproblems
ics45cprojectproblems_EXTERNAL_OBJECTS =

lib/libics45cprojectproblems.a: CMakeFiles/ics45cprojectproblems.dir/problems/problem3.cpp.o
lib/libics45cprojectproblems.a: CMakeFiles/ics45cprojectproblems.dir/build.make
lib/libics45cprojectproblems.a: CMakeFiles/ics45cprojectproblems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ics45c/projects/exercise1/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library lib/libics45cprojectproblems.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ics45cprojectproblems.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ics45cprojectproblems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ics45cprojectproblems.dir/build: lib/libics45cprojectproblems.a

.PHONY : CMakeFiles/ics45cprojectproblems.dir/build

CMakeFiles/ics45cprojectproblems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ics45cprojectproblems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ics45cprojectproblems.dir/clean

CMakeFiles/ics45cprojectproblems.dir/depend:
	cd /home/ics45c/projects/exercise1/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ics45c/projects/exercise1 /home/ics45c/projects/exercise1 /home/ics45c/projects/exercise1/out /home/ics45c/projects/exercise1/out /home/ics45c/projects/exercise1/out/CMakeFiles/ics45cprojectproblems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ics45cprojectproblems.dir/depend

