#ifndef INC_1_SPIELEENTWICKUNG1_CHARACTER_H
#define INC_1_SPIELEENTWICKUNG1_CHARACTER_H

#include "item.h"
#define INVENTORY_S_C 10

class Hero;//forward declaration

class Character{
private:
    string name;
    int health;
    int gold;
    Item inventory[INVENTORY_S_C];

public:
    void initCharacter(string name, int health, int gold);
    void attack(Hero &hero);
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

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
