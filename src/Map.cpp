//
// Created by david on 27/07/2022.
//
#include "Map.h"

//Placement of plants
void Map::setPlant(int x, int y, Player &player, Vector2<unsigned int> screenSize) {
    // Manage each type of plant and decrease player energy after its placement
    switch (player.getSelectedPlant()) {
        case 0:
            if(player.getEnergy()>=SUNFLOWER_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new Plant(x,y,PlantType::SUNFLOWER, screenSize.x));
                player.decreaseEnergy(SUNFLOWER_COST);
            }
            break;
        case 1:
            if(player.getEnergy()>=NUT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new Plant(x,y,PlantType::NUT, screenSize.x));
                player.decreaseEnergy(NUT_COST);
            }
            break;
        case 2:
            if(player.getEnergy()>=GREEN_PLANT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new ShooterPlant(x,y,ShooterType::GREEN, screenSize.x));
                player.decreaseEnergy(GREEN_PLANT_COST);
            }
            break;
        case 3:
            if(player.getEnergy()>=SNOW_PLANT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new ShooterPlant(x,y,ShooterType::SNOW, screenSize.x));
                player.decreaseEnergy(SNOW_PLANT_COST);
            }
            break;
        case 4:
            if(player.getEnergy()>=FIRE_PLANT_COST && isEmpty(x,y)){
                grid[x][y]=std::unique_ptr<Plant>(new ShooterPlant(x,y,ShooterType::FIRE, screenSize.x));
                player.decreaseEnergy(FIRE_PLANT_COST);
            }
            break;
        default:
            break;
    }

}
//control if a certain position of the grid is empty
bool Map::isEmpty(int x, int y) {
    if(this->grid[x][y]== nullptr)
        return true;
    return false;
}

Map::Map() {
    //create an empty grid
    for(auto & i : grid){
        for(auto & j : i){
            j= nullptr;
        }
    }
    //initialize all lawnmower true
    for(bool & i : lawnmower)
        i=true;

}

void Map::draw(sf::RenderTarget *target) {
    //draw the garden which is the rectangleShape where plants are placed
    sf::Vector2<unsigned int> size =target->getSize();
    garden.setSize({static_cast<float>(size.x*WIDTH_PROPORTION),static_cast<float>(size.y*HEIGHT_PROPORTION)});
    garden.setFillColor(sf::Color::Transparent);
    garden.setPosition((float)(size.x*0.12),(float)(size.y*0.12));
    target->draw(garden);

    for(int i=0;i<LENGTH_GRID;i++){
        for(int j=0;j<WIDTH_GRID;j++){
            //if there's a plant in a certain position of the grid -> draw it
            if(grid[i][j]!=nullptr) {
                int posx=(int)(garden.getPosition().x + (garden.getSize().x/LENGTH_GRID)*(float)i);
                int posy=(int)(garden.getPosition().y + (garden.getSize().y/WIDTH_GRID)*(float)j);
                grid[i][j]->draw(posx,posy, target);
            }
        }
    }

}

//Transform mouse position (onClick) to a certain position on the grid
sf::Vector2<unsigned int> Map::getPosition(const sf::Vector2<float> &point) {
    //get garden position
    int posx=(int)garden.getPosition().x;
    int posy=(int)garden.getPosition().y;
    //calculate cells dimensions
    int sizex=(int)garden.getSize().x/LENGTH_GRID;
    int sizey=(int)garden.getSize().y/WIDTH_GRID;

    unsigned int x = ((int)point.x - posx) / sizex;
    unsigned int y = ((int)point.y - posy) / sizey;
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

//the Map is scanned and each plants makes his actions
void Map::actions(Player &player, std::vector<Bullet*> &bullets) {
    for(int i=0;i<WIDTH_GRID;i++){
        for(int j=0;j<LENGTH_GRID;j++){
            if(grid[i][j]!= nullptr) {
                switch (grid[i][j]->getType()) {
                    //if type sunflower
                    case 's':
                        grid[i][j]->makeEnergy(player);//Sunflower creates energy and gives it to the player
                        break;
                    //if type shooterplant
                    case 'p':
                        //TODO ShooterPlants have to shoot here
                        grid[i][j]->shoot(bullets);
                        break;
                }
            }
        }
    }
}
#pragma clang diagnostic pop
