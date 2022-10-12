//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_MAP_H
#define PLANTVSZOMBIE_MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plants/Plant.h"
#include "Player.h"

#define LENGTH_GRID 9
#define WIDTH_GRID 5

#define SUNFLOWER_COST 2
#define NUT_COST 2
#define GREEN_PLANT_COST 4
#define SNOW_PLANT_COST 7
#define FIRE_PLANT_COST 7

class Map {
private:
    std::unique_ptr<Plant> grid [WIDTH_GRID][LENGTH_GRID]{};//TODO
    bool lawnmower [WIDTH_GRID]{};
    sf::RectangleShape garden;
public:
    Map();
    void draw(sf::RenderTarget* target);//TODO
    void setPlant(int x,int y, Player &player);//TODO
    bool isEmpty(int x, int y);
    bool isOver(const sf::Vector2<float> &point);
    sf::Vector2<unsigned int> getPosition(const sf::Vector2<float> &point);
};


#endif //PLANTVSZOMBIE_MAP_H
