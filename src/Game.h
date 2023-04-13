//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_GAME_H
#define PLANTVSZOMBIE_GAME_H
#define NUMBEROFPLANTS 5
#define ZOMBIE_ALIGNAMENT 0.09
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphics/Button.h"
#include "Graphics/Timer.h"
#include "Player.h"
#include "Map.h"
#include "Bullet.h"
#include "KillAchieve.h"

using namespace std;


using namespace sf;

class Game {
public:
    Game();
    ~Game();
    void update();
    void render();
    virtual void updateMousePosition();
    bool running();
    //enemies
    void updateZombies();
    void updateBullets();
private:

    RenderWindow* window;
    VideoMode vm;
    Event e;

    int x;

    Vector2f mousePosition;
    Player* player;
    Timer* crono;
    Map* map;
    bool incremented;
    KillAchieve* observer;

    //button

    Texture buttonImages[NUMBEROFPLANTS];
    Button* buttons[NUMBEROFPLANTS];

    void initVariables();
    void renderAchievements();
    void initWindow();
    void initTextures();
    void pollEvents();
    void drawBackground();

    //Enemies
    float rows[5]={0,0,0,0,0};
    float spawnTimer;
    float spawnTimerMax;
    vector<Zombie*> zombies;
    //bullets
    vector<Bullet*> bullets;
    ZombieType type;
    void initZombieVariables();
    void Collisions();

    //display GameOver
    void displayGameOver();





};


#endif //PLANTVSZOMBIE_GAME_H
