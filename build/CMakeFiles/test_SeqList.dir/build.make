# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/Vscode/Ctest/dataSA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/Vscode/Ctest/dataSA/build

# Include any dependencies generated for this target.
include CMakeFiles/test_SeqList.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_SeqList.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_SeqList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_SeqList.dir/flags.make

CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o: CMakeFiles/test_SeqList.dir/flags.make
CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o: ../test/test_SeqList.cpp
CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o: CMakeFiles/test_SeqList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Vscode/Ctest/dataSA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o -MF CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o.d -o CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o -c /mnt/hgfs/Vscode/Ctest/dataSA/test/test_SeqList.cpp

CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Vscode/Ctest/dataSA/test/test_SeqList.cpp > CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.i

CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Vscode/Ctest/dataSA/test/test_SeqList.cpp -o CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.s

# Object files for target test_SeqList
test_SeqList_OBJECTS = \
"CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o"

# External object files for target test_SeqList
test_SeqList_EXTERNAL_OBJECTS =

test_SeqList: CMakeFiles/test_SeqList.dir/test/test_SeqList.cpp.o
test_SeqList: CMakeFiles/test_SeqList.dir/build.make
test_SeqList: src/SeqList/libarseqlist.a
test_SeqList: lib/libgtest.a
test_SeqList: lib/libgtest_main.a
test_SeqList: lib/libgtest.a
test_SeqList: CMakeFiles/test_SeqList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/Vscode/Ctest/dataSA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_SeqList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_SeqList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_SeqList.dir/build: test_SeqList
.PHONY : CMakeFiles/test_SeqList.dir/build

CMakeFiles/test_SeqList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_SeqList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_SeqList.dir/clean

CMakeFiles/test_SeqList.dir/depend:
	cd /mnt/hgfs/Vscode/Ctest/dataSA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/Vscode/Ctest/dataSA /mnt/hgfs/Vscode/Ctest/dataSA /mnt/hgfs/Vscode/Ctest/dataSA/build /mnt/hgfs/Vscode/Ctest/dataSA/build /mnt/hgfs/Vscode/Ctest/dataSA/build/CMakeFiles/test_SeqList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_SeqList.dir/depend
