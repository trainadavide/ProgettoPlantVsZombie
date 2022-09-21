//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_GAME_H
#define PLANTVSZOMBIE_GAME_H
#define NUMBEROFPLANTS 5
#include <SFML/Graphics.hpp>
#include "Graphics/Button.h"
#include "Player.h"

using namespace sf;

class Game {
public:
    Game();
    virtual ~Game();

    void update();
    void render();
    virtual void updateMousePosition();

    const bool running() const;

private:

    RenderWindow *window;
    VideoMode vm;
    Event e;
    Vector2f mousePosition;

    Texture buttonImages[NUMBEROFPLANTS];
    Button* buttons[];

    void initVariables();
    void initWindow();
    void initTextures();
    void pollEvents();
    void drawBackground();
};


#endif //PLANTVSZOMBIE_GAME_H
