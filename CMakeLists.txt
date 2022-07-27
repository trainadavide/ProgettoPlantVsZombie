cmake_minimum_required(VERSION 3.21)
project(PlantVsZombie)

set(CMAKE_CXX_STANDARD 11)

add_executable(PlantVsZombie src/main.cpp src/Plants/Plant.cpp src/Plants/Plant.h src/Plants/Nut.cpp src/Plants/Nut.h)
