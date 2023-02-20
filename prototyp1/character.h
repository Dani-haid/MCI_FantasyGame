#ifndef INC_1_SPIELEENTWICKUNG1_CHARACTER_H
#define INC_1_SPIELEENTWICKUNG1_CHARACTER_H

#include "item.h"
struct Hero_t; //Forward declaration

struct Character_t{
    char name[256];
    int health;
    int gold;
    Item_t inventory[10];
};

void initCharacter(Character_t* character, char* name, int health, int gold);
void attack(Character_t* character, Hero_t* hero);

#endif //INC_1_SPIELEENTWICKUNG1_CHARACTER_H
