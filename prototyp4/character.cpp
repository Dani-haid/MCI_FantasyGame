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
        }else if(!this->inventory[index]){
            throw EmptySlotException("Error: Ungültiger Inventar Slot in getInventory.", index);
        }else{
            return this->inventory[index];
        }
    }
    catch (EmptySlotException& e){
        cout << e.what() <<" An Stelle: " << e.getIndex() << " ist kein Gegenstand gespeichert." << endl;
        this->inventory[index].reset();
        return this->inventory[index];
    }
};

int Character::addInventarItem(shared_ptr<Item> item){
    try{
        for (int i = 0; i < INVENTORY_S; ++i) {
            if(!this->inventory[i]){
                this->inventory[i] = item;
                cout << "Gegenstand " << this->inventory[i]->getName() << " wurde an Stelle " << i << " zum Inventar von " << *this << " hinzugefügt." << endl;
                return i;
            }
        }
        throw FullInventarException("Error: Inventar ist voll. Folgender Gegenstand kann nicht aufgenommen werden: ");
    }
    catch (FullInventarException& e){
        cout << "addInventarItem: " << e.what() << item->getName() << endl;
        return -1;
    }
};

shared_ptr<Item> Character::removeInventarItem(int slot) {
    if(slot < 0 || slot >= INVENTORY_S){
        throw IndexException("Error: Ungültiger Index in removeInventarItem.", slot);
    }
    else if(!this->inventory[slot]){
        return nullptr;
        //throw EmptySlotException("Error: Ungültiger Inventar Slot in removeInventarItem.", slot);
    }
    else{
        shared_ptr<Item> tempItem = this->inventory[slot];
        cout << "Gegenstand " << tempItem->getName() << " an Stelle " << slot << " wurde aus dem Inventar von " << this->getName() << " entfernt." << endl;
        this->inventory[slot].reset();
        return tempItem;
    }
};

ostream& operator<<(ostream& out, const Character& c){
out << c.getName();
return out;
}