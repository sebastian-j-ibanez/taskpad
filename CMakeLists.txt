cmake_minimum_required(VERSION 3.29.0)

project(taskpad)

add_executable(taskpad src/main.cpp)

find_package(Curses REQUIRED)
target_link_libraries(taskpad ${CURSES_LIBRARIES})
