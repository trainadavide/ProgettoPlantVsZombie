//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_BULLET_H
#define PLANTVSZOMBIE_BULLET_H


class Bullet {
private:
    int power;
    bool ice;
    float x;
    int y;
    virtual ~Bullet();

public:
    void miss();

    Bullet(int power, bool ice, float x, int y);
};


#endif //PLANTVSZOMBIE_BULLET_H
