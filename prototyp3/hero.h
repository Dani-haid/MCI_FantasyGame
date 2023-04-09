#ifndef PROTOTYP3_HERO_H
#define PROTOTYP3_HERO_H

#include "item.h"
#include "character.h"

#define EQUIPMENT_S 2

class Hero : public Character{
private:
    Item equipment[EQUIPMENT_S];

public:
    //constructor
    Hero(const string& name, int health, int gold, int armor, int magicResistance):
    Character(name, health, gold, armor, magicResistance){
        cout << "Heldin " << *this << " erstellt" << endl;
    }

    //destructor
    virtual ~Hero(){
        cout << *this << " verabschiedet sich in den Sonnenuntergang." << endl;
    };

    virtual void attack(Character& enemy) override;

    void sellItem(int index);
    bool fight(Character& enemy);

    Item getEquipment(int index);
    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);
    Item retrieveRandomLoot(Character &enemy);
};

ostream& operator<<(ostream& out, const Hero& h);

#endif //PROTOTYP3_HERO_H
