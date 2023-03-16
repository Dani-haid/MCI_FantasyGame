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
    void initCharacter(const string& name, int health, int gold);
    void attack(Hero &hero);
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);
    Item getInventory(int index);

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
        if(gold >= 0){
            this->gold = gold;
        }
    };
};



#endif //INC_1_SPIELEENTWICKUNG1_CHARACTER_H
