cmake_minimum_required(VERSION 3.17)
project(7542_Taller_Pages)

set(CMAKE_CXX_STANDARD 14)

add_executable(7542_Taller_Pages main.cpp common_src/Socket.cpp common_src/Socket.h common_src/SocketException.cpp common_src/SocketException.h common_src/OSexception.cpp common_src/OSexception.h)