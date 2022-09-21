//
// Created by Nayla on 26/07/2022.
//

#ifndef PROJECTPVSZ_ZOMBIE_H
#define PROJECTPVSZ_ZOMBIE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;

class Zombie {
private:
    Sprite zombie;
    int type;
    int hp;
    int hpMAx;
    int damage;
    int points;

    void initShape();
    void initVariables();

public:
    Zombie(float posX,float posY);
    ~Zombie();
    //Accessors
    FloatRect getBounds() const;
    //functions
    void update();
    void render(RenderTarget* target);


};


#endif //PROJECTPVSZ_ZOMBIE_H
