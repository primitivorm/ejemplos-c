# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/latino/src/ejemplos-c/gtk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/latino/src/ejemplos-c/gtk

# Include any dependencies generated for this target.
include CMakeFiles/example0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example0.dir/flags.make

CMakeFiles/example0.dir/example0.c.o: CMakeFiles/example0.dir/flags.make
CMakeFiles/example0.dir/example0.c.o: example0.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/latino/src/ejemplos-c/gtk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/example0.dir/example0.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/example0.dir/example0.c.o   -c /home/latino/src/ejemplos-c/gtk/example0.c

CMakeFiles/example0.dir/example0.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example0.dir/example0.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/latino/src/ejemplos-c/gtk/example0.c > CMakeFiles/example0.dir/example0.c.i

CMakeFiles/example0.dir/example0.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example0.dir/example0.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/latino/src/ejemplos-c/gtk/example0.c -o CMakeFiles/example0.dir/example0.c.s

CMakeFiles/example0.dir/example0.c.o.requires:

.PHONY : CMakeFiles/example0.dir/example0.c.o.requires

CMakeFiles/example0.dir/example0.c.o.provides: CMakeFiles/example0.dir/example0.c.o.requires
	$(MAKE) -f CMakeFiles/example0.dir/build.make CMakeFiles/example0.dir/example0.c.o.provides.build
.PHONY : CMakeFiles/example0.dir/example0.c.o.provides

CMakeFiles/example0.dir/example0.c.o.provides.build: CMakeFiles/example0.dir/example0.c.o


# Object files for target example0
example0_OBJECTS = \
"CMakeFiles/example0.dir/example0.c.o"

# External object files for target example0
example0_EXTERNAL_OBJECTS =

example0: CMakeFiles/example0.dir/example0.c.o
example0: CMakeFiles/example0.dir/build.make
example0: CMakeFiles/example0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/latino/src/ejemplos-c/gtk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable example0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example0.dir/build: example0

.PHONY : CMakeFiles/example0.dir/build

CMakeFiles/example0.dir/requires: CMakeFiles/example0.dir/example0.c.o.requires

.PHONY : CMakeFiles/example0.dir/requires

CMakeFiles/example0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example0.dir/clean

CMakeFiles/example0.dir/depend:
	cd /home/latino/src/ejemplos-c/gtk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/latino/src/ejemplos-c/gtk /home/latino/src/ejemplos-c/gtk /home/latino/src/ejemplos-c/gtk /home/latino/src/ejemplos-c/gtk /home/latino/src/ejemplos-c/gtk/CMakeFiles/example0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example0.dir/depend
