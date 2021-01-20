cmake_minimum_required(VERSION 3.15)
project(AVL)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVL main.cpp AVL.cpp AVL.h Node.cpp Node.h)