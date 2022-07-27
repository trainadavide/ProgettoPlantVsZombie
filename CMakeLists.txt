cmake_minimum_required(VERSION 3.21)
project(PlantVsZombie)

set(CMAKE_CXX_STANDARD 11)

add_executable(PlantVsZombie src/main.cpp src/Zombies/Zombie.cpp src/Zombies/Zombie.h BasicZombie.cpp BasicZombie.h TankZombie.cpp TankZombie.h cmake-build-debug/ShovelZombie.cpp cmake-build-debug/ShovelZombie.h)
