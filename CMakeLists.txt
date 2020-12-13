cmake_minimum_required(VERSION 3.17)
project(CommandSystem)

set(CMAKE_CXX_STANDARD 14)

add_library(CommandSystem library.cpp library.h LinkedList.h Command.cpp Command.h CommandSystem.cpp CommandSystem.h)