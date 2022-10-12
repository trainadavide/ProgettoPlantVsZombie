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

using namespace sf;

class Game {
public:
    Game();
    ~Game();

    void update();
    void render();
    virtual void updateMousePosition();

    bool running() const;

private:

    RenderWindow* window;
    VideoMode vm;
    Event e;
    Vector2f mousePosition;
    Player* player;
    Timer* crono;
    Map* map;
    int lastEnergyUp=0;

    Texture buttonImages[NUMBEROFPLANTS];
    Button* buttons[NUMBEROFPLANTS];

    void initVariables();
    void initWindow();
    void initTextures();
    void pollEvents();
    void drawBackground();
};


#endif //PLANTVSZOMBIE_GAME_H
