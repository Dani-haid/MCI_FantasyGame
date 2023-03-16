#ifndef PROTOTYP3_HERO_H
#define PROTOTYP3_HERO_H

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
    void initHero(const string& name, int health, int gold);
    void attack(Character& enemy);
    void sellItem(int index);
    bool fight(Character& enemy);

    Item getInventory(int index);
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

    Item getEquipment(int index);
    int addEquipmentItem(const Item& item);
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


    //setter:
    void setName(string name){
        this->name = name;
    };
    void setHealth(int health){
        if(health < 0){
            health = 0;
        }
        this->health = health;
    };
    void setGold(int gold){
        if(gold > 0){
            this->gold = gold;
        }
    };
};

#endif //PROTOTYP3_HERO_H
