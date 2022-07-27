cmake_minimum_required(VERSION 3.21)
project(PlantVsZombie)

set(CMAKE_CXX_STANDARD 11)

add_executable(PlantVsZombie src/main.cpp src/Plants/Plant.cpp src/Plants/Plant.h src/Plants/Nut.cpp src/Plants/Nut.h src/Plants/Sunflower.cpp src/Plants/Sunflower.h src/Player.cpp src/Player.h src/Plants/ShooterPlant.cpp src/Plants/ShooterPlant.h src/Bullet.cpp src/Bullet.h src/Plants/GreenPlant.cpp src/Plants/GreenPlant.h src/Plants/SnowPlant.cpp src/Plants/SnowPlant.h src/Plants/FirePlant.cpp src/Plants/FirePlant.h)
