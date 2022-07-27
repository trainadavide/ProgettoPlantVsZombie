cmake_minimum_required(VERSION 3.21)
project(PlantVsZombie)

set(CMAKE_CXX_STANDARD 11)

add_executable(PlantVsZombie src/main.cpp src/Zombies/Zombie.cpp src/Zombies/Zombie.h src/Zombies/BasicZombie.cpp src/Zombies/BasicZombie.h src/Zombies/TankZombie.cpp src/Zombies/TankZombie.h src/Zombies/ShovelZombie.cpp src/Zombies/ShovelZombie.h)
