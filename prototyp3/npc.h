#ifndef PROTOTYP3_NPC_H
#define PROTOTYP3_NPC_H

#include "character.h"
#include "item.h"


class Npc : public Character{
public:
    //constructor
    using Character::Character;

    ~Npc(){
        cout << this->name << " reitet in den Saloon." << endl;
    }
};


#endif //PROTOTYP3_NPC_H
