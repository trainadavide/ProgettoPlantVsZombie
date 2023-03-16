//
// Created by david on 28/09/2022.
//

#ifndef PLANTVSZOMBIE_TIMER_H
#define PLANTVSZOMBIE_TIMER_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Timer {
public:
    Timer();
    ~Timer();
    int getTime();
    void restart();
private:
    Clock* timer;

};


#endif //PLANTVSZOMBIE_TIMER_H
