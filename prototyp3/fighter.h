#ifndef PROTOTYP3_FIGHTER_H
#define PROTOTYP3_FIGHTER_H

#include "npc.h"
using namespace std;

class Fighter : public Npc{
private:
    int strength;

public:
    //default constructor
    Fighter():strength(0){};

    //constructor
    Fighter(const string& name, int health, int gold, int armor, int magicResistance, int strength)
    : Npc(name, health, gold, armor, magicResistance), strength(strength){
        cout << "Fighter " << this->name << " erstellt" << endl;
    };

    //destructor
    virtual ~Fighter(){};

    virtual void attack(Character& enemy) override;

    int getStrength() const {
        return strength;
    };

    void setStrength(int strength) {
        if(strength >= 0){
            this->strength = strength;
        }
    };
};

ostream& operator<<(ostream& out, Fighter& f);

#endif //PROTOTYP3_FIGHTER_H
