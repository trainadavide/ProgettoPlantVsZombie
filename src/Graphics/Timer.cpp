//
// Created by david on 28/09/2022.
//

#include "Timer.h"

Timer::~Timer() {
    delete this->timer;
}

Timer::Timer() {
    timer = new Clock();
}

int Timer::getTime() {
    return (int) timer->getElapsedTime().asSeconds();
}