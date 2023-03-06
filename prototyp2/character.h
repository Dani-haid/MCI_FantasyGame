#ifndef INC_1_SPIELEENTWICKUNG1_CHARACTER_H
#define INC_1_SPIELEENTWICKUNG1_CHARACTER_H

#include <string>
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
    string getName(){
        return name;
    };
    int getHealth(){
        return health;
    };
    int getGold(){
        return gold;
    };
    Item* getInventory(int index){
        if(index < 0 || index > 9){
            Item* item = NULL;
            item->initItem();
            return item;
        }
        return &this->inventory[index];
    };

    //setter:
    void setName(string name){
        this->name = name;
    };
    void setHealth(int health){
        //hier wird health aktuell ins negative gesetzt, soll ich das zulassen?
        this->health = health;
    };
    void setGold(int gold){
        if(gold > 0){
            this->gold = gold;
        }
    };
};



#endif //INC_1_SPIELEENTWICKUNG1_CHARACTER_H
