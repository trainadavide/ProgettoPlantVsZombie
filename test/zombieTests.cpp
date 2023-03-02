//
// Created by Nayla on 27/01/2023.
//
#include "lib/googletest/include/gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../src/Zombies/Zombie.h"
#include "../src/MainMenu.h"

TEST(Zombie, constructor){
    Zombie zombie(-5.5,0,ZombieType::BASIC);
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().x, -5.5);
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().y, 0);
    ASSERT_EQ(zombie.getType(ZombieType::BASIC),ZombieType::BASIC);
    Zombie zombie2(-5.5,0,ZombieType::TANK);
    ASSERT_EQ(zombie.getSprite(ZombieType::TANK).getPosition().x, -5.5);
    ASSERT_EQ(zombie.getSprite(ZombieType::TANK).getPosition().y, 0);
    ASSERT_EQ(zombie2.getType(ZombieType::TANK),ZombieType::TANK);
    Zombie zombie3(-5.5,0,ZombieType::SHOVEL);
    ASSERT_EQ(zombie.getSprite(ZombieType::SHOVEL).getPosition().x, -5.5);
    ASSERT_EQ(zombie.getSprite(ZombieType::SHOVEL).getPosition().y, 0);
    ASSERT_EQ(zombie3.getType(ZombieType::SHOVEL),ZombieType::SHOVEL);
}

TEST(Zombie,Move){
    Zombie zombie(0,0,ZombieType::BASIC);
    zombie.getSprite(ZombieType::BASIC).move(1,0);
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().x,zombie.getSpeed());
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().y,0);
}

TEST(Zombie, Damaged){
    Zombie zombie(0,0,ZombieType::BASIC);
    int health=zombie.getHealth();
    zombie.takeDamage(5);
    ASSERT_TRUE(zombie.getHitted());
    ASSERT_EQ(zombie.getHealth(), health-5);
}

TEST(Zombie, Speed){
    Zombie zombie(0,0,ZombieType::BASIC);
    zombie.setSpeed(10);
    ASSERT_EQ(zombie.getSpeed(),10);
}