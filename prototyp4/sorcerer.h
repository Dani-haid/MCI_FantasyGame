#ifndef PROTOTYP4_SORCERER_H
#define PROTOTYP4_SORCERER_H

#include "npc.h"
using namespace std;

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

    //destructor
    virtual ~Sorcerer(){};

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
