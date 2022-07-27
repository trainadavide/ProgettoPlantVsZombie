//
// Created by 0260863 on 26/07/2022.
//

#ifndef PROJECTPVSZ_ZOMBIE_H
#define PROJECTPVSZ_ZOMBIE_H


class Zombie {
private:
    int hp;
    float x;
    int y;
    int damage;
public:
    int getHp() const;
    void setHp(int hp);
    float getX()const;
    void setX(float x);
    int getY() const;
    void setY(int y);
    int getDamage()const;
    void setDamage(int damage);

    ~Zombie();

    void attack(Plant p);
    void takeDamage(int damage);
};


#endif //PROJECTPVSZ_ZOMBIE_H
