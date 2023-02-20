#ifndef INC_1_SPIELEENTWICKUNG1_HERO_H
#define INC_1_SPIELEENTWICKUNG1_HERO_H

#include "item.h"

struct Hero_t{
    char name[256];
    int health;
    int gold;
    Item_t inventory[10];
    Item_t equipment[2];
};

struct Character_t;

void initHero(Hero_t* hero, char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);
bool fight(Hero_t* hero, Character_t* enemy);


#endif //INC_1_SPIELEENTWICKUNG1_HERO_H


