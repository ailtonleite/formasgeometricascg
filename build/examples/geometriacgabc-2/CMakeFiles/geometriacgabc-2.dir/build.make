# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ailton/ufabc/cg/formasgeometricascg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ailton/ufabc/cg/formasgeometricascg/build

# Include any dependencies generated for this target.
include examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/progress.make

# Include the compile flags for this target's objects.
include examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/flags.make

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/flags.make
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.o: ../examples/geometriacgabc-2/main.cpp
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ailton/ufabc/cg/formasgeometricascg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.o"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/ccache /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.o -MF CMakeFiles/geometriacgabc-2.dir/main.cpp.o.d -o CMakeFiles/geometriacgabc-2.dir/main.cpp.o -c /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/main.cpp

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geometriacgabc-2.dir/main.cpp.i"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/main.cpp > CMakeFiles/geometriacgabc-2.dir/main.cpp.i

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geometriacgabc-2.dir/main.cpp.s"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/main.cpp -o CMakeFiles/geometriacgabc-2.dir/main.cpp.s

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/flags.make
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.o: ../examples/geometriacgabc-2/model.cpp
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ailton/ufabc/cg/formasgeometricascg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.o"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/ccache /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.o -MF CMakeFiles/geometriacgabc-2.dir/model.cpp.o.d -o CMakeFiles/geometriacgabc-2.dir/model.cpp.o -c /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/model.cpp

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geometriacgabc-2.dir/model.cpp.i"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/model.cpp > CMakeFiles/geometriacgabc-2.dir/model.cpp.i

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geometriacgabc-2.dir/model.cpp.s"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/model.cpp -o CMakeFiles/geometriacgabc-2.dir/model.cpp.s

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/flags.make
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.o: ../examples/geometriacgabc-2/window.cpp
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ailton/ufabc/cg/formasgeometricascg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.o"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/ccache /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.o -MF CMakeFiles/geometriacgabc-2.dir/window.cpp.o.d -o CMakeFiles/geometriacgabc-2.dir/window.cpp.o -c /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/window.cpp

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geometriacgabc-2.dir/window.cpp.i"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/window.cpp > CMakeFiles/geometriacgabc-2.dir/window.cpp.i

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geometriacgabc-2.dir/window.cpp.s"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/window.cpp -o CMakeFiles/geometriacgabc-2.dir/window.cpp.s

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/flags.make
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o: ../examples/geometriacgabc-2/trackball.cpp
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ailton/ufabc/cg/formasgeometricascg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/ccache /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o -MF CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o.d -o CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o -c /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/trackball.cpp

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geometriacgabc-2.dir/trackball.cpp.i"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/trackball.cpp > CMakeFiles/geometriacgabc-2.dir/trackball.cpp.i

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geometriacgabc-2.dir/trackball.cpp.s"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/lib/ccache/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/trackball.cpp -o CMakeFiles/geometriacgabc-2.dir/trackball.cpp.s

# Object files for target geometriacgabc-2
geometriacgabc__2_OBJECTS = \
"CMakeFiles/geometriacgabc-2.dir/main.cpp.o" \
"CMakeFiles/geometriacgabc-2.dir/model.cpp.o" \
"CMakeFiles/geometriacgabc-2.dir/window.cpp.o" \
"CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o"

# External object files for target geometriacgabc-2
geometriacgabc__2_EXTERNAL_OBJECTS =

bin/geometriacgabc-2: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/main.cpp.o
bin/geometriacgabc-2: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/model.cpp.o
bin/geometriacgabc-2: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/window.cpp.o
bin/geometriacgabc-2: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/trackball.cpp.o
bin/geometriacgabc-2: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/build.make
bin/geometriacgabc-2: abcg/libabcg.a
bin/geometriacgabc-2: /usr/lib/x86_64-linux-gnu/libGLX.so
bin/geometriacgabc-2: /usr/lib/x86_64-linux-gnu/libOpenGL.so
bin/geometriacgabc-2: /usr/lib/x86_64-linux-gnu/libGLEW.so
bin/geometriacgabc-2: abcg/external/fmt/libfmt.a
bin/geometriacgabc-2: abcg/external/imgui/libimgui.a
bin/geometriacgabc-2: /usr/lib/x86_64-linux-gnu/libSDL2main.a
bin/geometriacgabc-2: /usr/lib/x86_64-linux-gnu/libSDL2.so
bin/geometriacgabc-2: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
bin/geometriacgabc-2: examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ailton/ufabc/cg/formasgeometricascg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../../bin/geometriacgabc-2"
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/cmake -E remove_directory /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geometriacgabc-2.dir/link.txt --verbose=$(VERBOSE)
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/cmake -E make_directory /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2.dir
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/cmake -E copy_directory /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2/assets /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2.dir/assets
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/cmake -E copy /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2 /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2.dir/geometriacgabc-2
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/cmake -E remove /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/cmake -E rename /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2.dir /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && /usr/bin/cmake -E rm -rf /home/ailton/ufabc/cg/formasgeometricascg/build/bin/geometriacgabc-2.dir

# Rule to build all files generated by this target.
examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/build: bin/geometriacgabc-2
.PHONY : examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/build

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/clean:
	cd /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 && $(CMAKE_COMMAND) -P CMakeFiles/geometriacgabc-2.dir/cmake_clean.cmake
.PHONY : examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/clean

examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/depend:
	cd /home/ailton/ufabc/cg/formasgeometricascg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ailton/ufabc/cg/formasgeometricascg /home/ailton/ufabc/cg/formasgeometricascg/examples/geometriacgabc-2 /home/ailton/ufabc/cg/formasgeometricascg/build /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2 /home/ailton/ufabc/cg/formasgeometricascg/build/examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/geometriacgabc-2/CMakeFiles/geometriacgabc-2.dir/depend

