cmake_minimum_required(VERSION 3.12)
project(GenerationH C)

set(CMAKE_C_STANDARD 99)

add_executable(GenerationH main.c menu.c menu.h paramHGenerator.c paramHGenerator.h LEDOptionFunc.h Heart.h cardio.ino cardio.h)