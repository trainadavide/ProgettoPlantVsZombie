//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_GAME_H
#define PLANTVSZOMBIE_GAME_H
#include <SFML/Graphics.hpp>
#include "Zombies/Zombie.h"
#include "Graphics/Timer.h"
using namespace sf;
using namespace std;

class Game {
private:

    RenderWindow *window;
    VideoMode vm;
    Event e;
    int x;
    Timer* crono;
    void initVariables();
    void initWindow();
    void pollEvents();
    void drawBackground();
    //Enemies
    float rows[5]={0,0,0,0,0};
    float spawnTimer;
    float spawnTimerMax;
    vector<Zombie*> zombies;
    ZombieType type;
    void initZombieVariables();

public:
    Game();
    virtual ~Game();
    void update();
    void render();
    const bool running() const;
    //enemies
    void updateZombies();


};


#endif //PLANTVSZOMBIE_GAME_H
