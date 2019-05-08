cmake_minimum_required(VERSION 2.8)
project(supervga)
set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_executable(supervga src/main.cpp src/screen.cpp)

target_link_libraries(supervga vga)