# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Programe\Cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Programe\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\ProjectCode\DataStruct

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\ProjectCode\DataStruct\build

# Include any dependencies generated for this target.
include CMakeFiles/date_struct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/date_struct.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/date_struct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/date_struct.dir/flags.make

CMakeFiles/date_struct.dir/src/SeqList.c.obj: CMakeFiles/date_struct.dir/flags.make
CMakeFiles/date_struct.dir/src/SeqList.c.obj: CMakeFiles/date_struct.dir/includes_C.rsp
CMakeFiles/date_struct.dir/src/SeqList.c.obj: G:/ProjectCode/DataStruct/src/SeqList.c
CMakeFiles/date_struct.dir/src/SeqList.c.obj: CMakeFiles/date_struct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\ProjectCode\DataStruct\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/date_struct.dir/src/SeqList.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/date_struct.dir/src/SeqList.c.obj -MF CMakeFiles\date_struct.dir\src\SeqList.c.obj.d -o CMakeFiles\date_struct.dir\src\SeqList.c.obj -c G:\ProjectCode\DataStruct\src\SeqList.c

CMakeFiles/date_struct.dir/src/SeqList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/date_struct.dir/src/SeqList.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\ProjectCode\DataStruct\src\SeqList.c > CMakeFiles\date_struct.dir\src\SeqList.c.i

CMakeFiles/date_struct.dir/src/SeqList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/date_struct.dir/src/SeqList.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\ProjectCode\DataStruct\src\SeqList.c -o CMakeFiles\date_struct.dir\src\SeqList.c.s

CMakeFiles/date_struct.dir/src/main_test.c.obj: CMakeFiles/date_struct.dir/flags.make
CMakeFiles/date_struct.dir/src/main_test.c.obj: CMakeFiles/date_struct.dir/includes_C.rsp
CMakeFiles/date_struct.dir/src/main_test.c.obj: G:/ProjectCode/DataStruct/src/main_test.c
CMakeFiles/date_struct.dir/src/main_test.c.obj: CMakeFiles/date_struct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\ProjectCode\DataStruct\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/date_struct.dir/src/main_test.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/date_struct.dir/src/main_test.c.obj -MF CMakeFiles\date_struct.dir\src\main_test.c.obj.d -o CMakeFiles\date_struct.dir\src\main_test.c.obj -c G:\ProjectCode\DataStruct\src\main_test.c

CMakeFiles/date_struct.dir/src/main_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/date_struct.dir/src/main_test.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\ProjectCode\DataStruct\src\main_test.c > CMakeFiles\date_struct.dir\src\main_test.c.i

CMakeFiles/date_struct.dir/src/main_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/date_struct.dir/src/main_test.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\ProjectCode\DataStruct\src\main_test.c -o CMakeFiles\date_struct.dir\src\main_test.c.s

# Object files for target date_struct
date_struct_OBJECTS = \
"CMakeFiles/date_struct.dir/src/SeqList.c.obj" \
"CMakeFiles/date_struct.dir/src/main_test.c.obj"

# External object files for target date_struct
date_struct_EXTERNAL_OBJECTS =

date_struct.exe: CMakeFiles/date_struct.dir/src/SeqList.c.obj
date_struct.exe: CMakeFiles/date_struct.dir/src/main_test.c.obj
date_struct.exe: CMakeFiles/date_struct.dir/build.make
date_struct.exe: CMakeFiles/date_struct.dir/linkLibs.rsp
date_struct.exe: CMakeFiles/date_struct.dir/objects1.rsp
date_struct.exe: CMakeFiles/date_struct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\ProjectCode\DataStruct\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable date_struct.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\date_struct.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/date_struct.dir/build: date_struct.exe
.PHONY : CMakeFiles/date_struct.dir/build

CMakeFiles/date_struct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\date_struct.dir\cmake_clean.cmake
.PHONY : CMakeFiles/date_struct.dir/clean

CMakeFiles/date_struct.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\ProjectCode\DataStruct G:\ProjectCode\DataStruct G:\ProjectCode\DataStruct\build G:\ProjectCode\DataStruct\build G:\ProjectCode\DataStruct\build\CMakeFiles\date_struct.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/date_struct.dir/depend

