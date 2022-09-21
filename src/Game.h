//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_GAME_H
#define PLANTVSZOMBIE_GAME_H
#include <SFML/Graphics.hpp>
#include "Zombies/Zombie.h"
using namespace sf;
using namespace std;

class Game {
private:

    RenderWindow *window;
    VideoMode vm;
    Event e;

    void initVariables();
    void initWindow();
    void pollEvents();
    void drawBackground();
    //Enemies
    float spawnTimer;
    float spawnTimerMax;
    vector<Zombie*> zombies;
    void initZombies();

public:
    Game();
    virtual ~Game();

    void updateZombies();
    void update();
    void render();
    const bool running() const;


};


#endif //PLANTVSZOMBIE_GAME_H
