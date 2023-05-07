#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "character.h"
#include "npc.h"
#include "exceptions.h"

using namespace std;

//constructor
Hero::Hero(Game* manager, const string& name, int health, int gold, int armor, int magicResistance):
        Character(manager, name, health, gold, armor, magicResistance){
    memset(&equipment, 0, sizeof (equipment));
    cout << *this << " erstellt" << endl;
}

//destructor
Hero::~Hero(){
    cout << *this << " verabschiedet sich in den Sonnenuntergang." << endl;
};

void Hero::attack(shared_ptr<Character> enemy){
    int x = 15, y = 25;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y

    int damage = rand_num - enemy->getArmor();
    if(damage > 0){
        enemy->setHealth(enemy->getHealth()-damage);
    }else{
        cout << "Angriff von " << *this << " war wirkungslos" << endl;
    }
    cout << *this << " trifft " << *enemy << " für " << damage << " Lebenspunkte! "
    << *enemy << " besitzt jetzt noch " << enemy->getHealth() << " Lebenspunkte." << endl;
};

void Hero::sellItem(int index){
    shared_ptr<Item> tempItem = removeInventarItem(index);
    gold += tempItem->getValue();
    cout << tempItem << " wird für " << tempItem->getValue() <<
         " verkauft. " << *this << " besitzt nun " << gold << " Gold." << endl;
    manager->addSoldItem(tempItem);
};

void Hero::sellAllItems(){
    vector<int> keys;
    for(auto i : inventory){
        keys.push_back(i.first);
    }
    for(auto k : keys){
        sellItem(k);
    }
}





shared_ptr<Item> Hero::getEquipment(int index){
        if (index < 0 || index >= EQUIPMENT_S) {
            throw IndexException("Error: Ungültiger Index in getEquipment.", index);
        } else if (!equipment[index]) {
            throw EmptySlotException("Error: Ungültiger Inventar Slot in getEquipment. Hier ist kein Gegenstand gespeichert!", index);
        } else {
            return equipment[index];
        }
};

int Hero::addEquipmentItem(const shared_ptr<Item> item){
    for (int i = 0; i < EQUIPMENT_S; ++i) {
        if(!equipment[i]){
            equipment[i] = item; //hä?
            //cout << "Gegenstand " << equipment[i]->getName() << " wurde an Stelle " << i << " zum Equipment der Heldin hinzugefügt." << endl;
            return i;
        }
    }
    throw FullInventarException("Error: Inventar ist voll in addEquipmentItem.");
}

shared_ptr<Item> Hero::removeEquipmentItem(int slot){
    if(slot < 0 || slot >= EQUIPMENT_S){
        throw IndexException("Error: Ungültiger Index in removeEquipmentItem.", slot);
    }else if(!equipment[slot]){
        return shared_ptr<Item>();//korrekt?
        //throw EmptySlotException("Error: Ungültiger Inventar Slot in removeEquipmentItem.", slot);
    }else{
        shared_ptr<Item> tempItem = equipment[slot];
        cout << "Gegenstand " << tempItem << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        equipment[slot].reset();
        return tempItem;
    }
};

ostream& operator<<(ostream& out, const Hero& h){
    out << "Heldin " << h.getName();
    return out;
}