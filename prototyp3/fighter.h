#ifndef PROTOTYP3_FIGHTER_H
#define PROTOTYP3_FIGHTER_H

#include "npc.h"
using namespace std;

class Fighter : public Npc{
private:
    int strength;
public:
    //default constructor
    //Fighter():strength(0){};

    //constructor
    Fighter(const string& name, int health, int gold, int armor, int magicResistance, int strength):
    Npc(name, health, gold), strength(strength){};

    //destructor
    ~Fighter(){};

};

#endif //PROTOTYP3_FIGHTER_H
