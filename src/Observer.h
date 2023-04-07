//
// Created by david on 16/03/2023.
//

#ifndef PLANTVSZOMBIE_OBSERVER_H
#define PLANTVSZOMBIE_OBSERVER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graphics/Timer.h"

class Observer {
protected:
    sf::RenderTarget* window;
    sf::Font textFont;
    void initFont();
public:
    Observer(sf::RenderTarget* window);
    virtual ~Observer() = default;
    virtual void update(){};

};


#endif //PLANTVSZOMBIE_OBSERVER_H
