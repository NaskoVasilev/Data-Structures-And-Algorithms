# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/FootballTeam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FootballTeam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FootballTeam.dir/flags.make

CMakeFiles/FootballTeam.dir/main.cpp.obj: CMakeFiles/FootballTeam.dir/flags.make
CMakeFiles/FootballTeam.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FootballTeam.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FootballTeam.dir\main.cpp.obj -c "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\main.cpp"

CMakeFiles/FootballTeam.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FootballTeam.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\main.cpp" > CMakeFiles\FootballTeam.dir\main.cpp.i

CMakeFiles/FootballTeam.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FootballTeam.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\main.cpp" -o CMakeFiles\FootballTeam.dir\main.cpp.s

# Object files for target FootballTeam
FootballTeam_OBJECTS = \
"CMakeFiles/FootballTeam.dir/main.cpp.obj"

# External object files for target FootballTeam
FootballTeam_EXTERNAL_OBJECTS =

FootballTeam.exe: CMakeFiles/FootballTeam.dir/main.cpp.obj
FootballTeam.exe: CMakeFiles/FootballTeam.dir/build.make
FootballTeam.exe: CMakeFiles/FootballTeam.dir/linklibs.rsp
FootballTeam.exe: CMakeFiles/FootballTeam.dir/objects1.rsp
FootballTeam.exe: CMakeFiles/FootballTeam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FootballTeam.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FootballTeam.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FootballTeam.dir/build: FootballTeam.exe

.PHONY : CMakeFiles/FootballTeam.dir/build

CMakeFiles/FootballTeam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FootballTeam.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FootballTeam.dir/clean

CMakeFiles/FootballTeam.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\cmake-build-debug" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\cmake-build-debug" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FootballTeam\cmake-build-debug\CMakeFiles\FootballTeam.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/FootballTeam.dir/depend

