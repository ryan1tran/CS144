#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
    public:
        Character(std::string name, int hp, int attack, int defense);
        std::string getName();
        int getHp();
        int getAttack();
        int getDefense();

    private:
        std::string name;
        int hp;
        int attack;
        int defense;
};

#endif // CHARACTER_H
