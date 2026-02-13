#cmake_minimum_required(VERSION 4.1)
#project(untitled5 C)
#
#set(CMAKE_C_STANDARD 23)
#
#set(RAYLIB_PATH "C:/raylib")
#
#include_directories(${RAYLIB_PATH}/include)
#link_directories(${RAYLIB_PATH}/lib)
#
#add_executable(
#        untitled5
#        main.c
#)
#
#target_link_libraries(
#        untitled5
#        raylib
#        winmm
#        opengl32
#        gdi32
#)
#

cmake_minimum_required(VERSION 3.21)
project(Clock C)

set(CMAKE_C_STANDARD 11)

set(RAYLIB_PATH "C:/raylib")

include_directories(${RAYLIB_PATH}/include)
link_directories(${RAYLIB_PATH}/lib)

add_executable(Clock WIN32 main.c)

target_link_libraries(Clock
        raylib
        winmm
        opengl32
        gdi32
)
