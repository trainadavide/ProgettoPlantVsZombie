//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_GAME_H
#define PLANTVSZOMBIE_GAME_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Game {
public:
    Game();
    virtual ~Game();

    void update();
    void render();

    const bool running() const;

private:

    RenderWindow *window;
    VideoMode vm;
    Event e;

    void initVariables();
    void initWindow();
    void pollEvents();
    void drawBackground();
};


#endif //PLANTVSZOMBIE_GAME_H
