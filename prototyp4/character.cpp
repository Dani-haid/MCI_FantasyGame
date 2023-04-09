#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "exceptions.h"

using namespace std;

shared_ptr<Item> Character::getInventory(int index){
    try{
        if(index < 0 || index >= INVENTORY_S){
            throw IndexException("Error: Ungültiger Index in getInventory.", index);
        }else if(!inventory[index]){
            throw EmptySlotException("Error: Ungültiger Inventar Slot in getInventory.", index);
        }else{
            return inventory[index];
        }
    }
    catch (EmptySlotException& e){
        cout << e.what() <<" An Stelle: " << e.getIndex() << " ist kein Gegenstand gespeichert." << endl;
        inventory[index].reset();
        return inventory[index];
    }
};

int Character::addInventarItem(shared_ptr<Item> item){
    try{
        for (int i = 0; i < INVENTORY_S; ++i) {
            if(!this->inventory[i]){
                this->inventory[i] = item;
                cout << this->inventory[i] << " wurde an Stelle " << i << " zum Inventar von " << *this << " hinzugefügt." << endl;
                return i;
            }
        }
        throw FullInventarException("Error: Inventar ist voll. Folgender Gegenstand kann nicht aufgenommen werden: ");
    }
    catch (FullInventarException& e){
        cout << "addInventarItem: " << e.what() << item << endl;
        return -1;
    }
};

shared_ptr<Item> Character::removeInventarItem(int slot) {
    if(slot < 0 || slot >= INVENTORY_S){
        throw IndexException("Error: Ungültiger Index in removeInventarItem.", slot);
    }
    else if(!inventory[slot]){
        return shared_ptr<Item>();
        return nullptr;
        //throw EmptySlotException("Error: Ungültiger Inventar Slot in removeInventarItem.", slot);
    }
    else{
        shared_ptr<Item> tempItem = inventory[slot];
        cout << tempItem << " an Stelle " << slot << " wurde aus dem Inventar von " << *this << " entfernt." << endl;
        inventory[slot].reset();
        return tempItem;
    }
};

ostream& operator<<(ostream& out, const Character& c){
out << c.getName();
return out;
}