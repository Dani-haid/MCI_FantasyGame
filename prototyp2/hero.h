#ifndef INC_1_SPIELEENTWICKUNG1_HERO_H
#define INC_1_SPIELEENTWICKUNG1_HERO_H

#include "item.h"
using namespace std;

class Character;//forward declaration

class Hero{
private:
    string name;
    int health;
    int gold;
    Item inventory[10];
    Item equipment[2];

public:
    void initHero(string name, int health, int gold);
    void attack(Character &enemy);
    void sellItem(int index);
    bool fight(Character &enemy);

    //getter:
    string getName();
    int getHealth();
    int getGold();
    Item* getInventory(int index);
    Item* getEquipment(int index);

    //setter:
    void setName(string name);
    void setHealth(int health);
    void setGold(int gold);
};

#endif //INC_1_SPIELEENTWICKUNG1_HERO_H


