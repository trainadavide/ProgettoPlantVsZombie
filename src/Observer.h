//
// Created by david on 16/03/2023.
//

#ifndef PLANTVSZOMBIE_OBSERVER_H
#define PLANTVSZOMBIE_OBSERVER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graphics/Timer.h"

class Observer {
private:
    int zombieKilled=0;
    int achievement[5]={1,5,10,25,50};
    int achievementReached=0;
    sf::RenderTarget* window;
    sf::RectangleShape display;
    sf::Text achieve;
    sf::Font textFont;
    Timer* t=new Timer();
    void initFont();

public:
    virtual void update();
    Observer(sf::RenderTarget* window);
    void displayAchievements();
    virtual ~Observer() = default;
    void draw(sf::RenderTarget* window);
    bool isDrawable();
};


#endif //PLANTVSZOMBIE_OBSERVER_H
