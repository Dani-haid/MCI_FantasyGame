#ifndef PROTOTYP3_NPC_H
#define PROTOTYP3_NPC_H

#include "character.h"
#include "item.h"

#define INVENTORY_S_C 10


class Npc : public Character{
private:
    Item inventory[INVENTORY_S_C];

public:
    using Character::Character;
};


#endif //PROTOTYP3_NPC_H
