# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "D:\Software\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Software\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/flags.make

CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.obj: CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/flags.make
CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.obj"
	C:\LLVM\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\95__Unique_Binary_Search_Trees_II.dir\main.cpp.obj -c "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\main.cpp"

CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.i"
	C:\LLVM\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\main.cpp" > CMakeFiles\95__Unique_Binary_Search_Trees_II.dir\main.cpp.i

CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.s"
	C:\LLVM\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\main.cpp" -o CMakeFiles\95__Unique_Binary_Search_Trees_II.dir\main.cpp.s

# Object files for target 95__Unique_Binary_Search_Trees_II
95__Unique_Binary_Search_Trees_II_OBJECTS = \
"CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.obj"

# External object files for target 95__Unique_Binary_Search_Trees_II
95__Unique_Binary_Search_Trees_II_EXTERNAL_OBJECTS =

95__Unique_Binary_Search_Trees_II.exe: CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/main.cpp.obj
95__Unique_Binary_Search_Trees_II.exe: CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/build.make
95__Unique_Binary_Search_Trees_II.exe: CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/linklibs.rsp
95__Unique_Binary_Search_Trees_II.exe: CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/objects1.rsp
95__Unique_Binary_Search_Trees_II.exe: CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 95__Unique_Binary_Search_Trees_II.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\95__Unique_Binary_Search_Trees_II.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/build: 95__Unique_Binary_Search_Trees_II.exe

.PHONY : CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/build

CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\95__Unique_Binary_Search_Trees_II.dir\cmake_clean.cmake
.PHONY : CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/clean

CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II" "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II" "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\cmake-build-debug" "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\cmake-build-debug" "D:\Project\Algorithem\Leetcode\95. Unique Binary Search Trees II\cmake-build-debug\CMakeFiles\95__Unique_Binary_Search_Trees_II.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/95__Unique_Binary_Search_Trees_II.dir/depend
