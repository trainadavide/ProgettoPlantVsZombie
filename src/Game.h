//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_GAME_H
#define PLANTVSZOMBIE_GAME_H
#define NUMBEROFPLANTS 5
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphics/Button.h"
#include "Graphics/Timer.h"
#include "Player.h"
#include "Map.h"
#include "Zombies/Zombie.h"
using namespace std;

class Game {
public:
    Game();
    ~Game();
    void update();
    void render();
    virtual void updateMousePosition();
    const bool running() const;
    //enemies
    void updateZombies();
private:

    RenderWindow *window;
    VideoMode vm;
    Event e;
    int x;
    Vector2f mousePosition;
    Player* player;
    Timer* crono;
    Map* map;
    int lastEnergyUp=0;
    //button
    Texture buttonImages[NUMBEROFPLANTS];
    Button* buttons[NUMBEROFPLANTS];

    void initVariables();
    void initWindow();
    void initTextures();
    void pollEvents();
    void drawBackground();
    //Enemies
    float rows[5]={0,0,0,0,0};
    float spawnTimer;
    float spawnTimerMax;
    vector<Zombie*> zombies;
    ZombieType type;
    void initZombieVariables();




};


#endif //PLANTVSZOMBIE_GAME_H
