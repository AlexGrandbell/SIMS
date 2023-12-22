cmake_minimum_required(VERSION 3.25)
project(SIMS)

set(CMAKE_CXX_STANDARD 17)

add_executable(SIMS main.cpp SqList.h Student.cpp Student.h Exception.h menu.cpp menu.h tool.cpp tool.h)
