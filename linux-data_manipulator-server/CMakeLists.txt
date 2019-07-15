cmake_minimum_required(VERSION 3.14)
project(linux-data_manipulator-server)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(linux-data_manipulator-server main.cpp)
