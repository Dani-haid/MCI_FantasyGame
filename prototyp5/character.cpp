#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "exceptions.h"

using namespace std;

//constructor
Character::Character(Game* manager, const string& name, int health, int gold, int armor, int magicResistance)
    : manager(manager), name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){
    if(name.size()<1){
        throw WrongValueException("setName: ungültiger Wert für Name!");
    }
    if(health < 0 || gold < 0 || armor < 0 || magicResistance < 0){
        throw WrongValueException("Constructor: Negative Werte sind ungültig!");
    }
}

shared_ptr<Item> Character::getInventory(int index){
    if(inventory.find(index) != inventory.end()){
        //nachschauen ob der key bereits existiert
        return inventory[index]; //Achtung bei map und []. Wenn es key nicht gibt, wird dieser automatisch angelegt.
    }else{
        throw IndexException("Error: Ungültiger Index in getInventory.", index);
    }
};

int Character::addInventarItem(shared_ptr<Item> item){
    int id = nextItemID++;
    inventory.insert({id, item});
    cout << this->getInventory(id) << " wurde an Stelle " << id << " zum Inventar von " << *this << " hinzugefügt." << endl;
    return id;
 };

shared_ptr<Item> Character::removeInventarItem(int slot) {
    if (inventory.find(slot) != inventory.end()){//wenn der slot gefunden wurde
        shared_ptr<Item> tempItem = inventory[slot];
        cout << tempItem << " an Stelle " << slot << " wurde aus dem Inventar von " << *this << " entfernt." << endl;
        inventory.erase(inventory.begin()); //Item wird gelöscht
        return tempItem;
    }else{
        throw IndexException("Error: Ungültiger Index in removeInventarItem.", slot);
    }
};

ostream& operator<<(ostream& out, const Character& c){
out << c.getName();
return out;
}