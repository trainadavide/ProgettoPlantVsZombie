//
// Created by david on 28/09/2022.
//

#include "Timer.h"

Timer::~Timer() {
    delete timer;
}

Timer::Timer() {
    timer = new Clock();
}

//return the time passed (in seconds) since the start of the timer
int Timer::getTime() {
    return (int) timer->getElapsedTime().asSeconds();
}

void Timer::restart() {
    timer->restart();
}
