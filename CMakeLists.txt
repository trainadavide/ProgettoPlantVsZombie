cmake_minimum_required(VERSION 3.21)
project(PlantVsZombie)

set(CMAKE_CXX_STANDARD 11)


add_executable(PlantVsZombie src/main.cpp src/Game.cpp src/Game.h src/Plants/Plant.cpp src/Plants/Plant.h src/Player.cpp src/Player.h src/Plants/ShooterPlant.cpp src/Plants/ShooterPlant.h src/Bullet.cpp src/Bullet.h src/Map.cpp src/Map.h src/Zombies/Zombie.cpp src/Zombies/Zombie.h src/MainMenu.cpp src/MainMenu.h src/Graphics/Button.cpp src/Graphics/Button.h src/Graphics/Timer.cpp src/Graphics/Timer.h)


set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(PlantVsZombie sfml-system sfml-window sfml-graphics sfml-audio)

