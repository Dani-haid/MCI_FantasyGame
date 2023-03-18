#ifndef PROTOTYP3_CHARACTER_H
#define PROTOTYP3_CHARACTER_H

#include "item.h"
#define INVENTORY_S_C 10

using namespace std;

class Hero;//forward declaration

class Character{
protected:
    string name;
    int health;
    int gold;
    Item inventory[INVENTORY_S_C];
    int armor;
    int magicResistance;

public:
    //default constructor
    Character():name(""), health(0), gold(0), armor(0), magicResistance(0){};

    //constructor
    Character(const string& name, int health, int gold, int armor, int magicResistance):
    name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){
        cout << "Character " << this->name << " erstellt! " << endl;
    }

    //destructor
    ~Character(){
        cout << "Destructor Character " << this->name << endl;
    }

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

    int getArmor() const {
        return armor;
    }

    int getMagicResistance() const {
        return magicResistance;
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

    void setArmor(int armor) {
        if(armor >= 0){
            this->armor = armor;
        }
    };

    void setMagicResistance(int magicResistance) {
        if(magicResistance >= 0){
            this->magicResistance = magicResistance;
        }
    };
};



#endif //PROTOTYP3_CHARACTER_H
