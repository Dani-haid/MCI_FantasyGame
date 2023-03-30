#ifndef PROTOTYP4_NPC_H
#define PROTOTYP4_NPC_H

#include "character.h"
#include "item.h"


class Npc : public Character{
public:
    //constructor
    using Character::Character;

    //destructor
    ~Npc(){
        cout << this->getName() << " reitet in den Saloon." << endl;
    };
};



#endif //PROTOTYP4_NPC_H
