//
// Created by Nayla on 27/01/2023.
//
#include "lib/googletest/include/gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../src/Plants/Plant.h"
#include "../src/Game.h"
#include "../src/MainMenu.h"

TEST(Plant,Constructor){
    Plant plant(0,0,PlantType::GREEN,20);
    ASSERT_EQ(plant.getSprite(PlantType::GREEN).getPosition(),Vector2f(0,0));
    Plant plant1(0,0,PlantType::FIRE,20);
    ASSERT_EQ(plant1.getSprite(PlantType::FIRE).getPosition(),Vector2f(0,0));
    Plant plant2(0,0,PlantType::NUT,20);
    ASSERT_EQ(plant2.getSprite(PlantType::NUT).getPosition(),Vector2f(0,0));
    Plant plant3(0,0,PlantType::SNOW,20);
    ASSERT_EQ(plant3.getSprite(PlantType::SNOW).getPosition(),Vector2f(0,0));
    Plant plant4(0,0,PlantType::SUNFLOWER,20);
    ASSERT_EQ(plant4.getSprite(PlantType::SUNFLOWER).getPosition(),Vector2f(0,0));
}
TEST(Plant, Damaged){
    Plant plant(0,0,PlantType::GREEN,20);
    int hp=plant.getHp();
    plant.takeDamage(5);
    ASSERT_TRUE(plant.getHitted());
    ASSERT_EQ(plant.getHp(),hp-5);
    Plant plant1(0,0,PlantType::SUNFLOWER,20);
    int hp1=plant1.getHp();
    plant1.takeDamage(5);
    ASSERT_TRUE(plant1.getHitted());
    ASSERT_EQ(plant1.getHp(),hp1-5);
    Plant plant2(0,0,PlantType::SNOW,20);
    int hp2=plant2.getHp();
    plant2.takeDamage(5);
    ASSERT_TRUE(plant2.getHitted());
    ASSERT_EQ(plant2.getHp(),hp2-5);
    Plant plant3(0,0,PlantType::NUT,20);
    int hp3=plant3.getHp();
    plant3.takeDamage(5);
    ASSERT_TRUE(plant3.getHitted());
    ASSERT_EQ(plant3.getHp(),hp3-5);
    Plant plant4(0,0,PlantType::FIRE,20);
    int hp4=plant4.getHp();
    plant4.takeDamage(5);
    ASSERT_TRUE(plant4.getHitted());
    ASSERT_EQ(plant4.getHp(),hp4-5);
}