//
// Created by david on 28/09/2022.
//

#include "Timer.h"

Timer::~Timer() {
    delete this->timer;
}

Timer::Timer() {
    timer = new Clock();

    Font textFont;
    if(!textFont.loadFromFile("../font/balls-on-the-rampage/BallsoOnTheRampage.ttf")){
        printf("Font doesn't load");
    }

}

int Timer::getTime() {
    return (int) timer->getElapsedTime().asSeconds();
}


