# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/anton20241/rtc_work/master_slave_2dev_rs485

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton20241/rtc_work/master_slave_2dev_rs485/build

# Include any dependencies generated for this target.
include CMakeFiles/boost_client_sync.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boost_client_sync.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boost_client_sync.dir/flags.make

CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.o: CMakeFiles/boost_client_sync.dir/flags.make
CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.o: ../src/boost_client_sync.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.o -c /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_client_sync.cpp

CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_client_sync.cpp > CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.i

CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_client_sync.cpp -o CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.s

CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.o: CMakeFiles/boost_client_sync.dir/flags.make
CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.o: ../src/boost_rs485.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.o -c /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_rs485.cpp

CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_rs485.cpp > CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.i

CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_rs485.cpp -o CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.s

CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.o: CMakeFiles/boost_client_sync.dir/flags.make
CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.o: ../src/boost_rs485_ClientServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.o -c /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_rs485_ClientServer.cpp

CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_rs485_ClientServer.cpp > CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.i

CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton20241/rtc_work/master_slave_2dev_rs485/src/boost_rs485_ClientServer.cpp -o CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.s

CMakeFiles/boost_client_sync.dir/src/protocol.cpp.o: CMakeFiles/boost_client_sync.dir/flags.make
CMakeFiles/boost_client_sync.dir/src/protocol.cpp.o: ../src/protocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/boost_client_sync.dir/src/protocol.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_client_sync.dir/src/protocol.cpp.o -c /home/anton20241/rtc_work/master_slave_2dev_rs485/src/protocol.cpp

CMakeFiles/boost_client_sync.dir/src/protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_client_sync.dir/src/protocol.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton20241/rtc_work/master_slave_2dev_rs485/src/protocol.cpp > CMakeFiles/boost_client_sync.dir/src/protocol.cpp.i

CMakeFiles/boost_client_sync.dir/src/protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_client_sync.dir/src/protocol.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton20241/rtc_work/master_slave_2dev_rs485/src/protocol.cpp -o CMakeFiles/boost_client_sync.dir/src/protocol.cpp.s

CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.o: CMakeFiles/boost_client_sync.dir/flags.make
CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.o: ../src/tabl_reg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.o -c /home/anton20241/rtc_work/master_slave_2dev_rs485/src/tabl_reg.cpp

CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton20241/rtc_work/master_slave_2dev_rs485/src/tabl_reg.cpp > CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.i

CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton20241/rtc_work/master_slave_2dev_rs485/src/tabl_reg.cpp -o CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.s

CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.o: CMakeFiles/boost_client_sync.dir/flags.make
CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.o: ../src/umba_crc_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.o   -c /home/anton20241/rtc_work/master_slave_2dev_rs485/src/umba_crc_table.c

CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton20241/rtc_work/master_slave_2dev_rs485/src/umba_crc_table.c > CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.i

CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton20241/rtc_work/master_slave_2dev_rs485/src/umba_crc_table.c -o CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.s

# Object files for target boost_client_sync
boost_client_sync_OBJECTS = \
"CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.o" \
"CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.o" \
"CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.o" \
"CMakeFiles/boost_client_sync.dir/src/protocol.cpp.o" \
"CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.o" \
"CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.o"

# External object files for target boost_client_sync
boost_client_sync_EXTERNAL_OBJECTS =

boost_client_sync: CMakeFiles/boost_client_sync.dir/src/boost_client_sync.cpp.o
boost_client_sync: CMakeFiles/boost_client_sync.dir/src/boost_rs485.cpp.o
boost_client_sync: CMakeFiles/boost_client_sync.dir/src/boost_rs485_ClientServer.cpp.o
boost_client_sync: CMakeFiles/boost_client_sync.dir/src/protocol.cpp.o
boost_client_sync: CMakeFiles/boost_client_sync.dir/src/tabl_reg.cpp.o
boost_client_sync: CMakeFiles/boost_client_sync.dir/src/umba_crc_table.c.o
boost_client_sync: CMakeFiles/boost_client_sync.dir/build.make
boost_client_sync: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.2.0
boost_client_sync: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.2.0
boost_client_sync: CMakeFiles/boost_client_sync.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable boost_client_sync"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_client_sync.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boost_client_sync.dir/build: boost_client_sync

.PHONY : CMakeFiles/boost_client_sync.dir/build

CMakeFiles/boost_client_sync.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boost_client_sync.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boost_client_sync.dir/clean

CMakeFiles/boost_client_sync.dir/depend:
	cd /home/anton20241/rtc_work/master_slave_2dev_rs485/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton20241/rtc_work/master_slave_2dev_rs485 /home/anton20241/rtc_work/master_slave_2dev_rs485 /home/anton20241/rtc_work/master_slave_2dev_rs485/build /home/anton20241/rtc_work/master_slave_2dev_rs485/build /home/anton20241/rtc_work/master_slave_2dev_rs485/build/CMakeFiles/boost_client_sync.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boost_client_sync.dir/depend

