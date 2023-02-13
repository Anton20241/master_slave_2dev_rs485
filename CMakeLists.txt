cmake_minimum_required(VERSION 2.8)
PROJECT (rx_tx_project)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(SERVER_SRC src/boost_server.cpp
            src/boost_rs485.cpp
            src/boost_rs485_ClientServer.cpp
            src/protocol.cpp
            src/tabl_reg.cpp
            src/umba_crc_table.c
            include/boost_rs485.hpp
            include/boost_rs485_ClientServer.hpp
            include/i_transport.hpp
            include/protocol.hpp
            include/tabl_reg.hpp
            include/tabl_reg_config.hpp
            include/umba_crc_table.h)

set(CLIENT_SRC_0 src/boost_client_0.cpp
                src/boost_rs485.cpp
                src/boost_rs485_ClientServer.cpp
                src/protocol.cpp
                src/tabl_reg.cpp
                src/umba_crc_table.c
                include/boost_rs485.hpp
                include/boost_rs485_ClientServer.hpp
                include/i_transport.hpp
                include/protocol.hpp
                include/tabl_reg.hpp
                include/tabl_reg_config.hpp
                include/umba_crc_table.h)
                
set(CLIENT_SRC_1 src/boost_client_1.cpp
                src/boost_rs485.cpp
                src/boost_rs485_ClientServer.cpp
                src/protocol.cpp
                src/tabl_reg.cpp
                src/umba_crc_table.c
                include/boost_rs485.hpp
                include/boost_rs485_ClientServer.hpp
                include/i_transport.hpp
                include/protocol.hpp
                include/tabl_reg.hpp
                include/tabl_reg_config.hpp
                include/umba_crc_table.h)

#---------BOOST---------#
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.71.0 COMPONENTS thread REQUIRED)
if(Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})

add_executable( serial_pub src/serial_pub.cpp)
target_include_directories (serial_pub PRIVATE include/ src/)
target_link_libraries( serial_pub ${Boost_LIBRARIES} )

add_executable( serial_sub src/serial_sub.cpp)
target_include_directories (serial_sub PRIVATE include/ src/)
target_link_libraries( serial_sub ${Boost_LIBRARIES} )

add_executable( serial_sub_async src/serial_sub_async.cpp)
target_include_directories (serial_sub_async PRIVATE include/ src/)
target_link_libraries( serial_sub_async ${Boost_LIBRARIES} )

add_executable( boost_server ${SERVER_SRC})
target_include_directories (boost_server PRIVATE include/ src/)
target_link_libraries( boost_server ${Boost_LIBRARIES} )

add_executable( boost_client_0 ${CLIENT_SRC_0})
target_include_directories (boost_client_0 PRIVATE include/ src/)
target_link_libraries( boost_client_0 ${Boost_LIBRARIES} )

add_executable( boost_client_1 ${CLIENT_SRC_1})
target_include_directories (boost_client_1 PRIVATE include/ src/)
target_link_libraries( boost_client_1 ${Boost_LIBRARIES} )
endif()

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
#---------BOOST---------#


