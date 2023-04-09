#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"

using namespace std;

Item Character::getInventory(int index){
    if(index >= 0 && index < INVENTORY_S){
        if(this->inventory[index].getIsValid()){
            return this->inventory[index];
        }
    }
    return Item();
};

int Character::addInventarItem(const Item& item){
    for (int i = 0; i < INVENTORY_S; ++i) {
        //check ob der Platz im Inventar frei ist:
        if(!(inventory[i].getIsValid())){
            inventory[i] = item;
            //cout << "Gegenstand " << this->inventory[i].getName() << " wurde an Stelle " << i << " zum Inventar von " << *this << " hinzugefügt." << endl;
            return i;
        }
    }
    std::cout << "Inventar ist voll!" << std::endl;
    return -1;
};

Item Character::removeInventarItem(int slot) {
    if(slot >= 0 && slot < INVENTORY_S && inventory[slot].getIsValid()){
        Item tempItem = inventory[slot];
        inventory[slot].setIsValid(false);
        return tempItem;
    }
    return Item();
};

ostream& operator<<(ostream& out, const Character& c){
out << c.getName();
return out;
}