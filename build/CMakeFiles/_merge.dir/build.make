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

# Utility rule file for _merge.

# Include any custom commands dependencies for this target.
include CMakeFiles/_merge.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/_merge.dir/progress.make

CMakeFiles/_merge: libmerge.a

libmerge.a: src/SeqList/libarseqlist.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/hgfs/Vscode/Ctest/dataSA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating libmerge.a"
	ar crsT libmerge.a /mnt/hgfs/Vscode/Ctest/dataSA/build/src/SeqList/libarseqlist.a

_merge: CMakeFiles/_merge
_merge: libmerge.a
_merge: CMakeFiles/_merge.dir/build.make
.PHONY : _merge

# Rule to build all files generated by this target.
CMakeFiles/_merge.dir/build: _merge
.PHONY : CMakeFiles/_merge.dir/build

CMakeFiles/_merge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_merge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_merge.dir/clean

CMakeFiles/_merge.dir/depend:
	cd /mnt/hgfs/Vscode/Ctest/dataSA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/Vscode/Ctest/dataSA /mnt/hgfs/Vscode/Ctest/dataSA /mnt/hgfs/Vscode/Ctest/dataSA/build /mnt/hgfs/Vscode/Ctest/dataSA/build /mnt/hgfs/Vscode/Ctest/dataSA/build/CMakeFiles/_merge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_merge.dir/depend

