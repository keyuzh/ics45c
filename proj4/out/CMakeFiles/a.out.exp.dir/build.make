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
CMAKE_SOURCE_DIR = /home/ics45c/projects/proj4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ics45c/projects/proj4/out

# Include any dependencies generated for this target.
include CMakeFiles/a.out.exp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.exp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.exp.dir/flags.make

CMakeFiles/a.out.exp.dir/exp/expmain.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/exp/expmain.cpp.o: ../exp/expmain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.exp.dir/exp/expmain.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/exp/expmain.cpp.o -c /home/ics45c/projects/proj4/exp/expmain.cpp

CMakeFiles/a.out.exp.dir/exp/expmain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/exp/expmain.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/exp/expmain.cpp > CMakeFiles/a.out.exp.dir/exp/expmain.cpp.i

CMakeFiles/a.out.exp.dir/exp/expmain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/exp/expmain.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/exp/expmain.cpp -o CMakeFiles/a.out.exp.dir/exp/expmain.cpp.s

CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.o: ../app/BooEdit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.o -c /home/ics45c/projects/proj4/app/BooEdit.cpp

CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/BooEdit.cpp > CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.i

CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/BooEdit.cpp -o CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.s

CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.o: ../app/BooEditLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.o -c /home/ics45c/projects/proj4/app/BooEditLog.cpp

CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/BooEditLog.cpp > CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.i

CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/BooEditLog.cpp -o CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.s

CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.o: ../app/CommandStack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.o -c /home/ics45c/projects/proj4/app/CommandStack.cpp

CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/CommandStack.cpp > CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.i

CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/CommandStack.cpp -o CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.s

CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.o: ../app/EditorModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.o -c /home/ics45c/projects/proj4/app/EditorModel.cpp

CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/EditorModel.cpp > CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.i

CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/EditorModel.cpp -o CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.s

CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.o: ../app/InsertCharacter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.o -c /home/ics45c/projects/proj4/app/InsertCharacter.cpp

CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/InsertCharacter.cpp > CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.i

CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/InsertCharacter.cpp -o CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.s

CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.o: ../app/InteractionProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.o -c /home/ics45c/projects/proj4/app/InteractionProcessor.cpp

CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/InteractionProcessor.cpp > CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.i

CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/InteractionProcessor.cpp -o CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.s

CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.o: ../app/KeypressInteractionReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.o -c /home/ics45c/projects/proj4/app/KeypressInteractionReader.cpp

CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/KeypressInteractionReader.cpp > CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.i

CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/KeypressInteractionReader.cpp -o CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.s

CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.o: ../app/LineManipulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.o -c /home/ics45c/projects/proj4/app/LineManipulation.cpp

CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/LineManipulation.cpp > CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.i

CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/LineManipulation.cpp -o CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.s

CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.o: ../app/MoveCursor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.o -c /home/ics45c/projects/proj4/app/MoveCursor.cpp

CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/MoveCursor.cpp > CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.i

CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/MoveCursor.cpp -o CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.s

CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.o: ../app/NcursesEditorView.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.o -c /home/ics45c/projects/proj4/app/NcursesEditorView.cpp

CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/NcursesEditorView.cpp > CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.i

CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/NcursesEditorView.cpp -o CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.s

CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.o: CMakeFiles/a.out.exp.dir/flags.make
CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.o: ../app/NcursesKeypressReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.o -c /home/ics45c/projects/proj4/app/NcursesKeypressReader.cpp

CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics45c/projects/proj4/app/NcursesKeypressReader.cpp > CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.i

CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics45c/projects/proj4/app/NcursesKeypressReader.cpp -o CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.s

# Object files for target a.out.exp
a_out_exp_OBJECTS = \
"CMakeFiles/a.out.exp.dir/exp/expmain.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.o" \
"CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.o"

# External object files for target a.out.exp
a_out_exp_EXTERNAL_OBJECTS =

bin/a.out.exp: CMakeFiles/a.out.exp.dir/exp/expmain.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/BooEdit.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/BooEditLog.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/CommandStack.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/EditorModel.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/InsertCharacter.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/InteractionProcessor.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/KeypressInteractionReader.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/LineManipulation.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/MoveCursor.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/NcursesEditorView.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/app/NcursesKeypressReader.cpp.o
bin/a.out.exp: CMakeFiles/a.out.exp.dir/build.make
bin/a.out.exp: CMakeFiles/a.out.exp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ics45c/projects/proj4/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable bin/a.out.exp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.exp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.exp.dir/build: bin/a.out.exp

.PHONY : CMakeFiles/a.out.exp.dir/build

CMakeFiles/a.out.exp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.exp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.exp.dir/clean

CMakeFiles/a.out.exp.dir/depend:
	cd /home/ics45c/projects/proj4/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ics45c/projects/proj4 /home/ics45c/projects/proj4 /home/ics45c/projects/proj4/out /home/ics45c/projects/proj4/out /home/ics45c/projects/proj4/out/CMakeFiles/a.out.exp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.exp.dir/depend

