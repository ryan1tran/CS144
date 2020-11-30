#include "character.h"

Character::Character(std::string name, int hp, int attack, int defense)
{
    this->name = name;
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
}

std::string Character::getName()
{
    return name;
}

int Character::getHp()
{
    return hp;
}

int Character::getAttack()
{
    return attack;
}

int Character::getDefense()
{
    return defense;
}
