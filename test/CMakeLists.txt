cmake_minimum_required(VERSION 3.21)


add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp zombieTests.cpp plantTests.cpp playerTests.cpp ../src/Observer.cpp ../src/Observer.h ../src/Game.cpp ../src/Game.h ../src/Plants/Plant.cpp ../src/Plants/Plant.h ../src/Player.cpp ../src/Player.h ../src/Bullet.cpp ../src/Bullet.h ../src/Map.cpp ../src/Map.h ../src/Zombies/Zombie.cpp ../src/Zombies/Zombie.h ../src/MainMenu.cpp ../src/MainMenu.h ../src/Graphics/Button.cpp ../src/Graphics/Button.h ../src/Graphics/Timer.cpp ../src/Graphics/Timer.h)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main)

#detect SFML
set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(runAllTests sfml-system sfml-window sfml-graphics sfml-audio)

