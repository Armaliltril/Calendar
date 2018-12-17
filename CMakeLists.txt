cmake_minimum_required(VERSION 3.12)
project(Timetable_OS C)

set(CMAKE_C_STANDARD 11)

add_executable(Timetable_OS main.c handlers.h handlers.c calendar.c calendar.h)