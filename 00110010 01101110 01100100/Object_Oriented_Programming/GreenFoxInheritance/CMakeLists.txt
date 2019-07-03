cmake_minimum_required(VERSION 3.14)
project(GreenFoxInheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(GreenFoxInheritance main.cpp person.cpp person.h student.cpp student.h mentor.cpp mentor.h sponsor.cpp sponsor.h cohort.cpp cohort.h)