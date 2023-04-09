#ifndef PROTOTYP3_SORCERER_H
#define PROTOTYP3_SORCERER_H

#include "npc.h"
using namespace std;

class Sorcerer : public Npc{
private:
    int magicPower;
public:
    //default constructor
    Sorcerer():magicPower(0){};

    //constructor
    Sorcerer(const string& name, int health, int gold, int armor, int magicResistance, int magicPower)
    : Npc(name, health, gold, armor, magicResistance), magicPower(magicPower){
        cout << "Sorcerer " << *this << " erstellt" << endl;
    };

    //destructor in NPC

    virtual void attack(Character& enemy) override;

    int getMagicPower() const {
        return magicPower;
    };
    void setMagicPower(int magicPower) {
        if(magicPower >= 0){
            this->magicPower = magicPower;
        }
    };
};

ostream& operator<<(ostream& out, Sorcerer& s);

#endif //PROTOTYP3_SORCERER_H
