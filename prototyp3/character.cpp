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
    Item item;
    return item;
};

int Character::addInventarItem(const Item& item){
    for (int i = 0; i < INVENTORY_S; ++i) {
        //check ob der Platz im Inventar frei ist:
        if(!(this->inventory[i].getIsValid())){
            this->inventory[i] = item;
            cout << "Gegenstand " << this->inventory[i].getName() << " wurde an Stelle " << i << " zum Inventar von " << *this << " hinzugefügt." << endl;
            return i;
        }
    }
    std::cout << "Inventar ist voll!" << std::endl;
    return -1;
};

Item Character::removeInventarItem(int slot) {
    if(slot >= 0 && slot < INVENTORY_S && this->inventory[slot].getIsValid()){
        Item tempItem = this->inventory[slot];
        this->inventory[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Inventar des Characters entfernt." << endl;
        return tempItem;
    }
    Item tempItem;
    return tempItem;
}

ostream& operator<<(ostream& out, const Character& c){
out << c.getName();
return out;
}