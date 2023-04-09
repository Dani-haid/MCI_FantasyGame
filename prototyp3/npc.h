#ifndef PROTOTYP3_NPC_H
#define PROTOTYP3_NPC_H

#include "character.h"

class Npc : public Character{
public:
    //constructor
    using Character::Character;

    //destructor
    virtual ~Npc(){
        if(health > 0){
            cout << *this << " reitet in den Saloon." << endl;
        }else{
            cout << *this << " liegt am Boden und rührt sich nicht mehr." << endl;
        }
    };
};



#endif //PROTOTYP3_NPC_H
