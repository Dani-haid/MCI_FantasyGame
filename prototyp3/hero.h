#ifndef PROTOTYP3_HERO_H
#define PROTOTYP3_HERO_H

#include "item.h"
#include "character.h"
#include "npc.h"

#define EQUIPMENT_S 2

class Hero : public Character{
private:
    Item equipment[EQUIPMENT_S];

public:
    //constructor
    using Character::Character; //eigene stream Ausgabe erstellen

    //destructor
    virtual ~Hero(){
        cout << this->name << " verabschiedet sich in den Sonnenuntergang." << endl;
    }; //braucht man hier virtual destructor oder normal?

    virtual void attack(Character& enemy) override;

    void sellItem(int index);
    bool fight(Character& enemy);

    //Item getInventory(int index);
    //int addInventarItem(const Item& item);
    //Item removeInventarItem(int slot);

    Item getEquipment(int index);
    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);
};

ostream& operator<<(ostream& out, const Hero& h);

#endif //PROTOTYP3_HERO_H
