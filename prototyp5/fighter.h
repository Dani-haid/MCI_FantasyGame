#ifndef PROTOTYP4_FIGHTER_H
#define PROTOTYP4_FIGHTER_H

#include "npc.h"
using namespace std;

class Fighter : public Npc{
private:
    int strength;

public:
    //constructor
    Fighter(Game* manager, const string& name, int health, int gold, int armor, int magicResistance, int strength);

    //destructor in NPC

    virtual void attack(Character& enemy) override;

    int getStrength() const {
        return strength;
    };

    void setStrength(int strength) {
        if(strength >= 0){
            this->strength = strength;
        }else{
            throw WrongValueException("setStrength: negativer Wert ist ungültig!");
        }
    };
};

ostream& operator<<(ostream& out, Fighter& f);

#endif //PROTOTYP4_FIGHTER_H
