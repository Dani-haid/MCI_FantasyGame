#ifndef PROTOTYP4_SORCERER_H
#define PROTOTYP4_SORCERER_H

#include "npc.h"
using namespace std;

class Sorcerer : public Npc{
private:
    int magicPower;
public:
    //constructor
    Sorcerer(Game* manager, const string& name, int health, int gold, int armor, int magicResistance, int magicPower);

    //destructor in NPC

    virtual void attack(Character& enemy) override;

    int getMagicPower() const {
        return magicPower;
    };
    void setMagicPower(int magicPower) {
        if(magicPower >= 0){
            this->magicPower = magicPower;
        }else{
            throw WrongValueException("setMagicPower: negativer Wert ist ungültig!");
        }
    };
};

ostream& operator<<(ostream& out, Sorcerer& s);

#endif //PROTOTYP4_SORCERER_H
