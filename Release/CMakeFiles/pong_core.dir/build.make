# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Zack HDoubler\source\repos\pong"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Zack HDoubler\source\repos\pong\Release"

# Include any dependencies generated for this target.
include CMakeFiles/pong_core.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pong_core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pong_core.dir/flags.make

CMakeFiles/pong_core.dir/src/CompView.cpp.obj: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/CompView.cpp.obj: CMakeFiles/pong_core.dir/includes_CXX.rsp
CMakeFiles/pong_core.dir/src/CompView.cpp.obj: ../src/CompView.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack HDoubler\source\repos\pong\Release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pong_core.dir/src/CompView.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pong_core.dir\src\CompView.cpp.obj -c "C:\Users\Zack HDoubler\source\repos\pong\src\CompView.cpp"

CMakeFiles/pong_core.dir/src/CompView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/CompView.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack HDoubler\source\repos\pong\src\CompView.cpp" > CMakeFiles\pong_core.dir\src\CompView.cpp.i

CMakeFiles/pong_core.dir/src/CompView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/CompView.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack HDoubler\source\repos\pong\src\CompView.cpp" -o CMakeFiles\pong_core.dir\src\CompView.cpp.s

CMakeFiles/pong_core.dir/src/GameView.cpp.obj: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/GameView.cpp.obj: CMakeFiles/pong_core.dir/includes_CXX.rsp
CMakeFiles/pong_core.dir/src/GameView.cpp.obj: ../src/GameView.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack HDoubler\source\repos\pong\Release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pong_core.dir/src/GameView.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pong_core.dir\src\GameView.cpp.obj -c "C:\Users\Zack HDoubler\source\repos\pong\src\GameView.cpp"

CMakeFiles/pong_core.dir/src/GameView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/GameView.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack HDoubler\source\repos\pong\src\GameView.cpp" > CMakeFiles\pong_core.dir\src\GameView.cpp.i

CMakeFiles/pong_core.dir/src/GameView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/GameView.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack HDoubler\source\repos\pong\src\GameView.cpp" -o CMakeFiles\pong_core.dir\src\GameView.cpp.s

CMakeFiles/pong_core.dir/src/PlayerView.cpp.obj: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/PlayerView.cpp.obj: CMakeFiles/pong_core.dir/includes_CXX.rsp
CMakeFiles/pong_core.dir/src/PlayerView.cpp.obj: ../src/PlayerView.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack HDoubler\source\repos\pong\Release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pong_core.dir/src/PlayerView.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pong_core.dir\src\PlayerView.cpp.obj -c "C:\Users\Zack HDoubler\source\repos\pong\src\PlayerView.cpp"

CMakeFiles/pong_core.dir/src/PlayerView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/PlayerView.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack HDoubler\source\repos\pong\src\PlayerView.cpp" > CMakeFiles\pong_core.dir\src\PlayerView.cpp.i

CMakeFiles/pong_core.dir/src/PlayerView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/PlayerView.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack HDoubler\source\repos\pong\src\PlayerView.cpp" -o CMakeFiles\pong_core.dir\src\PlayerView.cpp.s

CMakeFiles/pong_core.dir/src/SingleRandom.cpp.obj: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/SingleRandom.cpp.obj: CMakeFiles/pong_core.dir/includes_CXX.rsp
CMakeFiles/pong_core.dir/src/SingleRandom.cpp.obj: ../src/SingleRandom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack HDoubler\source\repos\pong\Release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pong_core.dir/src/SingleRandom.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pong_core.dir\src\SingleRandom.cpp.obj -c "C:\Users\Zack HDoubler\source\repos\pong\src\SingleRandom.cpp"

CMakeFiles/pong_core.dir/src/SingleRandom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/SingleRandom.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack HDoubler\source\repos\pong\src\SingleRandom.cpp" > CMakeFiles\pong_core.dir\src\SingleRandom.cpp.i

CMakeFiles/pong_core.dir/src/SingleRandom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/SingleRandom.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack HDoubler\source\repos\pong\src\SingleRandom.cpp" -o CMakeFiles\pong_core.dir\src\SingleRandom.cpp.s

CMakeFiles/pong_core.dir/src/StatePlaying.cpp.obj: CMakeFiles/pong_core.dir/flags.make
CMakeFiles/pong_core.dir/src/StatePlaying.cpp.obj: CMakeFiles/pong_core.dir/includes_CXX.rsp
CMakeFiles/pong_core.dir/src/StatePlaying.cpp.obj: ../src/StatePlaying.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Zack HDoubler\source\repos\pong\Release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pong_core.dir/src/StatePlaying.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pong_core.dir\src\StatePlaying.cpp.obj -c "C:\Users\Zack HDoubler\source\repos\pong\src\StatePlaying.cpp"

CMakeFiles/pong_core.dir/src/StatePlaying.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pong_core.dir/src/StatePlaying.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Zack HDoubler\source\repos\pong\src\StatePlaying.cpp" > CMakeFiles\pong_core.dir\src\StatePlaying.cpp.i

CMakeFiles/pong_core.dir/src/StatePlaying.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pong_core.dir/src/StatePlaying.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Zack HDoubler\source\repos\pong\src\StatePlaying.cpp" -o CMakeFiles\pong_core.dir\src\StatePlaying.cpp.s

# Object files for target pong_core
pong_core_OBJECTS = \
"CMakeFiles/pong_core.dir/src/CompView.cpp.obj" \
"CMakeFiles/pong_core.dir/src/GameView.cpp.obj" \
"CMakeFiles/pong_core.dir/src/PlayerView.cpp.obj" \
"CMakeFiles/pong_core.dir/src/SingleRandom.cpp.obj" \
"CMakeFiles/pong_core.dir/src/StatePlaying.cpp.obj"

# External object files for target pong_core
pong_core_EXTERNAL_OBJECTS =

libpong_core.a: CMakeFiles/pong_core.dir/src/CompView.cpp.obj
libpong_core.a: CMakeFiles/pong_core.dir/src/GameView.cpp.obj
libpong_core.a: CMakeFiles/pong_core.dir/src/PlayerView.cpp.obj
libpong_core.a: CMakeFiles/pong_core.dir/src/SingleRandom.cpp.obj
libpong_core.a: CMakeFiles/pong_core.dir/src/StatePlaying.cpp.obj
libpong_core.a: CMakeFiles/pong_core.dir/build.make
libpong_core.a: CMakeFiles/pong_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Zack HDoubler\source\repos\pong\Release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libpong_core.a"
	$(CMAKE_COMMAND) -P CMakeFiles\pong_core.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pong_core.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pong_core.dir/build: libpong_core.a

.PHONY : CMakeFiles/pong_core.dir/build

CMakeFiles/pong_core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pong_core.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pong_core.dir/clean

CMakeFiles/pong_core.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Zack HDoubler\source\repos\pong" "C:\Users\Zack HDoubler\source\repos\pong" "C:\Users\Zack HDoubler\source\repos\pong\Release" "C:\Users\Zack HDoubler\source\repos\pong\Release" "C:\Users\Zack HDoubler\source\repos\pong\Release\CMakeFiles\pong_core.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pong_core.dir/depend

