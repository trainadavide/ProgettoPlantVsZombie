//
// Created by Nayla on 08/02/2023.
//
#include "lib/googletest/include/gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../src/Plants/Plant.h"
#include "../src/MainMenu.h"

TEST(Player, constructor){
    int energy=5;
    Player player(energy,{5,5});
    ASSERT_EQ(player.getEnergy(),energy);
    ASSERT_EQ(player.getenergyisplay().getFillColor(),sf::Color::Black);
}

TEST(Player,Energy){
    int energy=5;
    Player player(energy,{5,5});
    player.increaseEnergy();
    ASSERT_EQ(player.getEnergy(),6);
}