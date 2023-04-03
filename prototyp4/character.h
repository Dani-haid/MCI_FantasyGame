#ifndef PROTOTYP4_CHARACTER_H
#define PROTOTYP4_CHARACTER_H

#include "item.h"

#define INVENTORY_S 10

using namespace std;

class Hero;//forward declaration

class Character{
protected:
    string name;
    int health;
    int gold;
    Item* inventory[INVENTORY_S] = {}; //zuerst alle mit NULL initialisieren
    int armor;
    int magicResistance;

public:
    //default constructor
    Character():name(""), health(0), gold(0), armor(0), magicResistance(0){};

    //constructor
    Character(const string& name, int health, int gold, int armor, int magicResistance):
    name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){
    }

    //destructor
    virtual ~Character(){};

    virtual void attack(Character& character) = 0;

    int addInventarItem(shared_ptr<Item> item);
    Item* removeInventarItem(int slot);
    Item* getInventory(int index);

    //getter:
    string getName() const{
        return name;
    };
    int getHealth() const{
        return health;
    };
    int getGold() const{
        return gold;
    };

    int getArmor() const{
        return armor;
    }

    int getMagicResistance() const{
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

ostream& operator<<(ostream& out, const Character& c);


#endif //PROTOTYP4_CHARACTER_H
