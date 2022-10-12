//
// Created by david on 27/07/2022.
//
#include "Map.h"
#include "Plants/Plant.h"
#include "Plants/ShooterPlant.h"


void Map::setPlant(int x, int y, Player &player) {
    switch (player.getSelectedPlant()) {
        case 0:
            if(player.getEnergy()>=SUNFLOWER_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new Plant(x,y,PlantType::SUNFLOWER));
                std::cout<<"Sunflower placed";
                player.decreaseEnergy(SUNFLOWER_COST);
            }
            break;
        case 1:
            if(player.getEnergy()>=NUT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new Plant(x,y,PlantType::NUT));
                std::cout<<"Nut placed";
                player.decreaseEnergy(NUT_COST);
            }
            break;
        case 2:
            if(player.getEnergy()>=GREEN_PLANT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new ShooterPlant(x,y,ShooterType::GREEN));
                std::cout<<"GreenPlant placed";
                player.decreaseEnergy(GREEN_PLANT_COST);
            }
            break;
        case 3:
            if(player.getEnergy()>=SNOW_PLANT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new ShooterPlant(x,y,ShooterType::SNOW));
                std::cout<<"SnowPlant placed";
                player.decreaseEnergy(SNOW_PLANT_COST);
            }
            break;
        case 4:
            if(player.getEnergy()>=FIRE_PLANT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new ShooterPlant(x,y,ShooterType::FIRE));
                std::cout<<"FirePlant placed";
                player.decreaseEnergy(FIRE_PLANT_COST);
            }
            break;
        default:
            break;
    }

}

bool Map::isEmpty(int x, int y) {
    if(this->grid[x][y]== nullptr)
        return true;
    return false;
}

Map::Map() {
    for(auto & i : grid){
        for(auto & j : i){
            j= nullptr;
        }
    }
    for(bool & i : lawnmower)
        i=true;

}

void Map::draw(sf::RenderTarget *target) {
    sf::Vector2<unsigned int> size =target->getSize();
    garden.setSize({static_cast<float>(size.x*0.68),static_cast<float>(size.y*0.82)});
    garden.setOutlineThickness(10);
    garden.setOutlineColor(sf::Color::Black);
    garden.setFillColor(sf::Color::Transparent);
    garden.setPosition((float)(size.x*0.12),(float)(size.y*0.12));
    target->draw(garden);

    for(int i=0;i<LENGTH_GRID;i++){
        for(int j=0;j<WIDTH_GRID;j++){
            if(grid[i][j]!=nullptr) {
                int posx=(int)(garden.getPosition().x + (garden.getSize().x/LENGTH_GRID)*(float)i);
                int posy=(int)(garden.getPosition().y + (garden.getSize().y/WIDTH_GRID)*(float)j);
                grid[i][j]->draw(posx,posy, target);
            }
        }
    }

}

sf::Vector2<unsigned int> Map::getPosition(const sf::Vector2<float> &point) {
    int posx=(int)garden.getPosition().x;
    int posy=(int)garden.getPosition().y;
    int sizex=(int)garden.getSize().x/LENGTH_GRID;
    int sizey=(int)garden.getSize().y/WIDTH_GRID;

    unsigned int x = ((int)point.x - posx) / sizex;
    unsigned int y = ((int)point.y - posy) / sizey;
    std::cout<<x<<" "<<y<<std::endl;
    return {x,y};
}

bool Map::isOver(const sf::Vector2<float> &point) {
    if(this->garden.getGlobalBounds().contains(point))
        return true;
    else
        return false;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"
void Map::actions(Player &player) {
    for(int i=0;i<WIDTH_GRID;i++){
        for(int j=0;j<LENGTH_GRID;j++){
            if(grid[i][j]!= nullptr) {
                if (grid[i][j]->getType() == 's')
                    grid[i][j]->makeEnergy(player);
            }
        }
    }
}
#pragma clang diagnostic pop
