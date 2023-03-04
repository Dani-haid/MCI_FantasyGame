#ifndef INC_1_SPIELEENTWICKUNG1_HERO_H
#define INC_1_SPIELEENTWICKUNG1_HERO_H

#include "item.h"
#define INVENTORY_S 10
#define EQUIPMENT_S 2

class Character;//forward declaration

class Hero{
private:
    string name;
    int health;
    int gold;
    Item inventory[INVENTORY_S];
    Item equipment[EQUIPMENT_S];

public:
    void initHero(string name, int health, int gold);
    void attack(Character& enemy);
    void sellItem(int index);
    bool fight(Character& enemy);
    int addInventarItem(const Item& item);
    int addEquipmentItem(const Item& item);
    Item removeInventarItem(int slot);
    Item removeEquipmentItem(int slot);

    //getter:
    string getName();
    int getHealth();
    int getGold();
    Item* getInventory(int index); //hier besser Pointer oder Referenz als Rückgabeargument verwenden?
    Item* getEquipment(int index);

    //setter:
    void setName(string name);
    void setHealth(int health);
    void setGold(int gold);
};

#endif //INC_1_SPIELEENTWICKUNG1_HERO_H


