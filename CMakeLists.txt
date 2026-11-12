cmake_minimum_required(VERSION 3.10.0)
project(PWr_in_Space_ASC VERSION 0.1.0 LANGUAGES C)

add_executable(PWr_in_Space_ASC main.c pid.c)

include(CTest)
enable_testing()

