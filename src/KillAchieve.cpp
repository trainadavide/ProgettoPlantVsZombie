//
// Created by david on 21/03/2023.
//

#include "KillAchieve.h"


void KillAchieve::update() {
    zombieKilled++;
    if(zombieKilled==achievement[achievementReached]){
        displayAchievements();
        achievementReached++;
        t->restart();
    }
}

void KillAchieve::displayAchievements() {
    display.setSize({1000,200});
    display.setPosition(1700,0);
    display.setFillColor(sf::Color::White);

    achieve.setCharacterSize(50);
    achieve.setFillColor(sf::Color::Black);
    achieve.setPosition(1730, 50);
    achieve.setFont(textFont);

    sf::String text;
    switch (achievementReached){
        case 0:
            text="Novizio: uccidi 1 zombie";
            break;
        case 1:
            text="Cacciatore: uccidi 5 zombie";
            break;
        case 2:
            text="Macellaio: uccidi 10 zombie";
            break;
        case 3:
            text="Carnefice: uccidi 25 zombie";
            break;
        case 4:
            text="Bomba Atomica: uccidi 50 zombie";
            break;
    }

    achieve.setString(text);
}

void KillAchieve::draw() {
    window->draw(display);
    window->draw(achieve);
}

bool KillAchieve::isDrawable() {
    return t->getTime()<=5;
}



KillAchieve::KillAchieve(sf::RenderTarget *window) : Observer(window) {

}
