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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\80670\CLionProjects\go_tcp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\80670\CLionProjects\go_tcp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/go_tcp-simugtp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/go_tcp-simugtp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/go_tcp-simugtp.dir/flags.make

CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.obj: CMakeFiles/go_tcp-simugtp.dir/flags.make
CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.obj: ../simugtp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\80670\CLionProjects\go_tcp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.obj"
	C:\PragmaDev\share\3rdparty\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\go_tcp-simugtp.dir\simugtp.cpp.obj -c C:\Users\80670\CLionProjects\go_tcp\simugtp.cpp

CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.i"
	C:\PragmaDev\share\3rdparty\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\80670\CLionProjects\go_tcp\simugtp.cpp > CMakeFiles\go_tcp-simugtp.dir\simugtp.cpp.i

CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.s"
	C:\PragmaDev\share\3rdparty\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\80670\CLionProjects\go_tcp\simugtp.cpp -o CMakeFiles\go_tcp-simugtp.dir\simugtp.cpp.s

CMakeFiles/go_tcp-simugtp.dir/decode.cpp.obj: CMakeFiles/go_tcp-simugtp.dir/flags.make
CMakeFiles/go_tcp-simugtp.dir/decode.cpp.obj: ../decode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\80670\CLionProjects\go_tcp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/go_tcp-simugtp.dir/decode.cpp.obj"
	C:\PragmaDev\share\3rdparty\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\go_tcp-simugtp.dir\decode.cpp.obj -c C:\Users\80670\CLionProjects\go_tcp\decode.cpp

CMakeFiles/go_tcp-simugtp.dir/decode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_tcp-simugtp.dir/decode.cpp.i"
	C:\PragmaDev\share\3rdparty\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\80670\CLionProjects\go_tcp\decode.cpp > CMakeFiles\go_tcp-simugtp.dir\decode.cpp.i

CMakeFiles/go_tcp-simugtp.dir/decode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_tcp-simugtp.dir/decode.cpp.s"
	C:\PragmaDev\share\3rdparty\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\80670\CLionProjects\go_tcp\decode.cpp -o CMakeFiles\go_tcp-simugtp.dir\decode.cpp.s

# Object files for target go_tcp-simugtp
go_tcp__simugtp_OBJECTS = \
"CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.obj" \
"CMakeFiles/go_tcp-simugtp.dir/decode.cpp.obj"

# External object files for target go_tcp-simugtp
go_tcp__simugtp_EXTERNAL_OBJECTS =

go_tcp-simugtp.exe: CMakeFiles/go_tcp-simugtp.dir/simugtp.cpp.obj
go_tcp-simugtp.exe: CMakeFiles/go_tcp-simugtp.dir/decode.cpp.obj
go_tcp-simugtp.exe: CMakeFiles/go_tcp-simugtp.dir/build.make
go_tcp-simugtp.exe: CMakeFiles/go_tcp-simugtp.dir/linklibs.rsp
go_tcp-simugtp.exe: CMakeFiles/go_tcp-simugtp.dir/objects1.rsp
go_tcp-simugtp.exe: CMakeFiles/go_tcp-simugtp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\80670\CLionProjects\go_tcp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable go_tcp-simugtp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\go_tcp-simugtp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/go_tcp-simugtp.dir/build: go_tcp-simugtp.exe

.PHONY : CMakeFiles/go_tcp-simugtp.dir/build

CMakeFiles/go_tcp-simugtp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\go_tcp-simugtp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/go_tcp-simugtp.dir/clean

CMakeFiles/go_tcp-simugtp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\80670\CLionProjects\go_tcp C:\Users\80670\CLionProjects\go_tcp C:\Users\80670\CLionProjects\go_tcp\cmake-build-debug C:\Users\80670\CLionProjects\go_tcp\cmake-build-debug C:\Users\80670\CLionProjects\go_tcp\cmake-build-debug\CMakeFiles\go_tcp-simugtp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/go_tcp-simugtp.dir/depend
