#ifndef PROTOTYP3_HERO_H
#define PROTOTYP3_HERO_H

#include "item.h"
#include "character.h"
#define INVENTORY_S 10
#define EQUIPMENT_S 2

class Hero : public Character{
private:
    Item inventory[INVENTORY_S];
    Item equipment[EQUIPMENT_S];

public:
    //constructor
    using Character::Character;

    void attack(Character& enemy);
    void sellItem(int index);
    bool fight(Character& enemy);

    Item getInventory(int index);
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

    Item getEquipment(int index);
    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);
};

#endif //PROTOTYP3_HERO_H
