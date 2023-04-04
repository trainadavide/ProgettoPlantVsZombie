//
// Created by Nayla on 27/01/2023.
//
#include "lib/googletest/include/gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../src/MainMenu.h"
#include "../src/Game.h"

TEST(Zombie, constructor){
    Zombie zombie(0,0,ZombieType::BASIC);
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().x, 0);
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().y, 0);
    ASSERT_EQ(zombie.getType(ZombieType::BASIC),ZombieType::BASIC);
    Zombie zombie2(0,0,ZombieType::TANK);
    ASSERT_EQ(zombie.getSprite(ZombieType::TANK).getPosition().x, 0);
    ASSERT_EQ(zombie.getSprite(ZombieType::TANK).getPosition().y, 0);
    ASSERT_EQ(zombie2.getType(ZombieType::TANK),ZombieType::TANK);
    Zombie zombie3(0,0,ZombieType::SHOVEL);
    ASSERT_EQ(zombie.getSprite(ZombieType::SHOVEL).getPosition().x, 0);
    ASSERT_EQ(zombie.getSprite(ZombieType::SHOVEL).getPosition().y, 0);
    ASSERT_EQ(zombie3.getType(ZombieType::SHOVEL),ZombieType::SHOVEL);
}

TEST(Zombie,Move){
    Zombie zombie(-1,0,ZombieType::BASIC);
    zombie.getSprite(ZombieType::BASIC).move(1,0);
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().x,0);
    ASSERT_EQ(zombie.getSprite(ZombieType::BASIC).getPosition().y,0);
}

TEST(Zombie, Damaged){
    Zombie zombie(0,0,ZombieType::BASIC);
    int health=zombie.getHealth();
    zombie.takeDamage(5);
    ASSERT_TRUE(zombie.getHitted());
    ASSERT_EQ(zombie.getHealth(), health-5);
}

TEST(Zombie,Collisions){
    Player player(10,{VideoMode::getDesktopMode().width,VideoMode::getDesktopMode().height});
    Map* mappa = new Map();
    mappa->setPlant(0,0,player,{VideoMode::getDesktopMode().width,VideoMode::getDesktopMode().height});
    Zombie zombie(mappa->getPlantPosition(0,0).x,mappa->getPlantPosition(0,0).y,ZombieType::BASIC);
    ASSERT_EQ(mappa->getPlantPosition(0,0).x,zombie.getSprite(ZombieType::BASIC).getPosition().x);
    ASSERT_EQ(mappa->getPlantPosition(0,0).y,zombie.getSprite(ZombieType::BASIC).getPosition().y);
}

TEST(Zombie, Speed){
    Zombie zombie(0,0,ZombieType::BASIC);
    zombie.setSpeed(10);
    ASSERT_EQ(zombie.getSpeed(),10);
}