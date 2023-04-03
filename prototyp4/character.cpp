#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "exceptions.h"

using namespace std;

Item* Character::getInventory(int index){
    if(index < 0 || index >= INVENTORY_S){
        throw IndexException("Error: Ungültiger Index in getInventory.", index);
    }else if(this->inventory[index]){
        return this->inventory[index];
    }
    Item* item = NULL;
    return item;
};

int Character::addInventarItem(shared_ptr<Item> item){
    for (int i = 0; i < INVENTORY_S; ++i) {
        //check ob der Platz im Inventar frei ist:
        if(!this->inventory[i]){
            this->inventory[i] = &*item;//häää?
            //cout << "Gegenstand " << this->inventory[i].getName() << " wurde an Stelle " << i << " zum Inventar von " << *this << " hinzugefügt." << endl;
            return i;
        }
    }
    std::cout << "Inventar ist voll!" << std::endl;
    return -1;
};

Item* Character::removeInventarItem(int slot) {
    if(slot < 0 || slot >= INVENTORY_S){
        throw IndexException("Error: Ungültiger Index in removeInventarItem.", slot);
    } else if(this->inventory[slot]){
        Item* tempItem = this->inventory[slot];
        this->inventory[slot] = NULL;
        //cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Inventar von " << this->getName() << " entfernt." << endl;
        return tempItem;
    }
    Item* tempItem = NULL;
    return tempItem;
};

ostream& operator<<(ostream& out, const Character& c){
out << c.getName();
return out;
}