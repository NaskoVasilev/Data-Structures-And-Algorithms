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
CMAKE_SOURCE_DIR = "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/FirstExam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FirstExam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FirstExam.dir/flags.make

CMakeFiles/FirstExam.dir/main.cpp.obj: CMakeFiles/FirstExam.dir/flags.make
CMakeFiles/FirstExam.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FirstExam.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FirstExam.dir\main.cpp.obj -c "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\main.cpp"

CMakeFiles/FirstExam.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstExam.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\main.cpp" > CMakeFiles\FirstExam.dir\main.cpp.i

CMakeFiles/FirstExam.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstExam.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\main.cpp" -o CMakeFiles\FirstExam.dir\main.cpp.s

# Object files for target FirstExam
FirstExam_OBJECTS = \
"CMakeFiles/FirstExam.dir/main.cpp.obj"

# External object files for target FirstExam
FirstExam_EXTERNAL_OBJECTS =

FirstExam.exe: CMakeFiles/FirstExam.dir/main.cpp.obj
FirstExam.exe: CMakeFiles/FirstExam.dir/build.make
FirstExam.exe: CMakeFiles/FirstExam.dir/linklibs.rsp
FirstExam.exe: CMakeFiles/FirstExam.dir/objects1.rsp
FirstExam.exe: CMakeFiles/FirstExam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FirstExam.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FirstExam.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FirstExam.dir/build: FirstExam.exe

.PHONY : CMakeFiles/FirstExam.dir/build

CMakeFiles/FirstExam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FirstExam.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FirstExam.dir/clean

CMakeFiles/FirstExam.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\cmake-build-debug" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\cmake-build-debug" "E:\SU\Semester 3\SDA\Homeworks\01_Homework\FirstExam\cmake-build-debug\CMakeFiles\FirstExam.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/FirstExam.dir/depend

