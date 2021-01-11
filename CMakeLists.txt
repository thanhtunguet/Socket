cmake_minimum_required(VERSION 3.17)
project(Socket)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Socket server.cpp Socket.hpp)
