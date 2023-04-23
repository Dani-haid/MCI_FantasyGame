#ifndef PROTOTYP4_NPC_H
#define PROTOTYP4_NPC_H

#include "character.h"
#include <iostream>

class Npc : public Character{
public:
    //constructor
    using Character::Character;

    //destructor
    virtual ~Npc(){
        cout << "Dest: ";
        if(health > 0){
            cout << *this << " reitet in den Saloon." << endl;
        }else{
            cout << *this << " liegt am Boden." << endl;
        }
    };
};



#endif //PROTOTYP4_NPC_H
