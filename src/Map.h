//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_MAP_H
#define PLANTVSZOMBIE_MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plants/Plant.h"
#include "Plants/ShooterPlant.h"
#include "Player.h"

#define WIDTH_PROPORTION 0.68
#define HEIGHT_PROPORTION 0.82

#define WIDTH_GRID 5
#define LENGTH_GRID 9

#define SUNFLOWER_COST 2
#define NUT_COST 2
#define GREEN_PLANT_COST 4
#define SNOW_PLANT_COST 7
#define FIRE_PLANT_COST 7

class Map {
private:
    std::unique_ptr<Plant> grid [LENGTH_GRID][WIDTH_GRID];
    bool lawnmower [WIDTH_GRID];
    sf::RectangleShape garden;
public:
    Map();
    void draw(sf::RenderTarget* target);
    void setPlant(int x, int y, Player &player, sf::Vector2<unsigned int> screenSize);
    void actions(Player &player, std::vector<Bullet*> &bullets, int screensize);
    bool isEmpty(int x, int y);
    bool isOver(const sf::Vector2<float> &point);
    sf::Vector2<unsigned int> getPosition(const sf::Vector2<float> &point);
};


#endif //PLANTVSZOMBIE_MAP_H
