#ifndef PROTOTYP3_SORCERER_H
#define PROTOTYP3_SORCERER_H

#include "npc.h"

class Sorcerer : public Npc{
private:
    int magicPower;
public:
    //default constructor
    Sorcerer(){};

    //constructor
    Sorcerer(const string& name, int health, int gold, int armor, int magicResistance, int magicPower)
    : Npc(name, health, gold, armor, magicResistance), magicPower(magicPower){
        cout << "Sorcerer " << this->name << " erstellt" << endl;
    };

    int getMagicPower() const {
        return magicPower;
    };
    void setMagicPower(int magicPower) {
        if(magicPower >= 0){
            this->magicPower = magicPower;
        }
    };
};

#endif //PROTOTYP3_SORCERER_H
