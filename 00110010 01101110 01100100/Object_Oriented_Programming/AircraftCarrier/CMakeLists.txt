cmake_minimum_required(VERSION 3.14)
project(AircraftCarrier)

set(CMAKE_CXX_STANDARD 14)

add_executable(AircraftCarrier main.cpp F16.cpp F16.h f16.cpp f16.h f35.cpp f35.h carrier.cpp carrier.h)