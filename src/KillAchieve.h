//
// Created by david on 21/03/2023.
//

#ifndef PLANTVSZOMBIE_KILLACHIEVE_H
#define PLANTVSZOMBIE_KILLACHIEVE_H
#include <SFML/Graphics.hpp>
#include "./Graphics/Timer.h"
#include "Observer.h"

class KillAchieve: public Observer{
    private:
        int zombieKilled=0;
        int achievement[5]={1,5,10,25,50};
        int achievementReached=0;
        sf::RectangleShape display;
        sf::Text achieve;
        Timer* t=new Timer();
        void displayAchievements();

    public:
        KillAchieve(sf::RenderTarget* window);
        void update() override;
        void draw() const;
        bool isDrawable();

};


#endif //PLANTVSZOMBIE_KILLACHIEVE_H
