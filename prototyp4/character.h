#ifndef PROTOTYP4_CHARACTER_H
#define PROTOTYP4_CHARACTER_H

#include "item.h"
#include "exceptions.h"
#include <memory>

#define INVENTORY_S 10

using namespace std;

class Character{
protected:
    string name;
    int health;
    int gold;
    shared_ptr<Item> inventory[INVENTORY_S] = {}; //zuerst alle mit nullptr initialisieren
    int armor;
    int magicResistance;

public:
    //default constructor
    Character():name(""), health(0), gold(0), armor(0), magicResistance(0){};

    //constructor
    Character(const string& name, int health, int gold, int armor, int magicResistance):
    name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){
        if(name.size()<1){
            throw WrongValueException("setName: ungültiger Wert für Name!");
        }
        if(health < 0 || gold < 0 || armor < 0 || magicResistance < 0){
            throw WrongValueException("Constructor: Negative Werte sind ungültig!");
        }
    }

    //destructor
    virtual ~Character(){};

    virtual void attack(Character& character) = 0;

    int addInventarItem(shared_ptr<Item> item);
    shared_ptr<Item> removeInventarItem(int slot);
    shared_ptr<Item> getInventory(int index);

    //getter:
    const string &getName() const{
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
        if(name.size()>0){
            this->name = name;
        }else{
            throw WrongValueException("setName: ungültiger Wert für Name!");
        }
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
        }else{
            throw WrongValueException("setGold: negativer Wert ist ungültig!");
        }
    };

    void setArmor(int armor) {
        if(armor >= 0){
            this->armor = armor;
        }else{
            throw WrongValueException("setArmor: negativer Wert ist ungültig");
        }
    };

    void setMagicResistance(int magicResistance) {
        if(magicResistance >= 0){
            this->magicResistance = magicResistance;
        }else{
            throw WrongValueException("setMagicResistance: negativer Wert ist ungültig");
        }
    };
};

ostream& operator<<(ostream& out, const Character& c);


#endif //PROTOTYP4_CHARACTER_H
