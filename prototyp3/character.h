#ifndef PROTOTYP3_CHARACTER_H
#define PROTOTYP3_CHARACTER_H

#include "item.h"

#define INVENTORY_S 10

using namespace std;

class Character{
protected:
    string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    Item inventory[INVENTORY_S];

public:
    //default constructor
    Character():name(""), health(0), gold(0), armor(0), magicResistance(0){};

    //constructor
    Character(const string& name, int health, int gold, int armor, int magicResistance):
    name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){};

    //destructor
    virtual ~Character(){};

    virtual void attack(Character& character) = 0;

    Item getInventory(int index);
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

    //getter:
    const string& getName() const{
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
    void setName(const string& name){
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


#endif //PROTOTYP3_CHARACTER_H
