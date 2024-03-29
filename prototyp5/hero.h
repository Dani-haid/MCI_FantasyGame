#ifndef PROTOTYP4_HERO_H
#define PROTOTYP4_HERO_H

#include "item.h"
#include "character.h"
#include <memory>

#define EQUIPMENT_S 2

class Hero : public Character{
private:
    shared_ptr<Item> equipment[EQUIPMENT_S];

public:
    //constructor
    Hero(Game* manager, const string& name, int health, int gold, int armor, int magicResistance);

    //destructor
    virtual ~Hero();

    virtual void attack(shared_ptr<Character> enemy) override;

    void sellItem(int index);
    void sellAllItems();


    shared_ptr<Item> getEquipment(int index);
    int addEquipmentItem(const shared_ptr<Item> item);
    shared_ptr<Item> removeEquipmentItem(int slot);

};

ostream& operator<<(ostream& out, const Hero& h);

#endif //PROTOTYP4_HERO_H
