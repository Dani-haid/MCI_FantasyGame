#ifndef INC_1_SPIELEENTWICKUNG1_HERO_H
#define INC_1_SPIELEENTWICKUNG1_HERO_H

#include <string>
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
    string getName(){
        return name;
    };
    int getHealth(){
        return health;
    };
    int getGold(){
        return gold;
    };
    Item* getInventory(int index){//hier besser Pointer oder Referenz als Rückgabeargument verwenden?
        if(index < 0 || index > 9){
            Item* item;
            item->initItem();
            return item;
        }
        return &this->inventory[index];
    };

    Item* getEquipment(int index){
        if(index < 0 || index > 1){
            Item* item;
            item->initItem();
            return item;
        }
        return &this->equipment[index];
    };

    //setter:
    void setName(string name){
        this->name = name;
    };
    void setHealth(int health){
        this->health = health;
    };
    void setGold(int gold){
        if(gold > 0){
            this->gold = gold;
        }
    };
};

#endif //INC_1_SPIELEENTWICKUNG1_HERO_H


