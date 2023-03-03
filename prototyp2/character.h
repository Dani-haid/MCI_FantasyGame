#ifndef INC_1_SPIELEENTWICKUNG1_CHARACTER_H
#define INC_1_SPIELEENTWICKUNG1_CHARACTER_H

#include "item.h"
using namespace std;

class Hero;

class Character{
private:
    string name;
    int health;
    int gold;
    Item inventory[10];

public:
    void initCharacter(string name, int health, int gold);
    void attack(Hero &hero);
    int addInventarItem(const Item& item);

    //getter:
    string getName();
    int getHealth();
    int getGold();
    Item* getInventory(int index);

    //setter:
    void setName(string name);
    void setHealth(int health);
    void setGold(int gold);
};



#endif //INC_1_SPIELEENTWICKUNG1_CHARACTER_H
