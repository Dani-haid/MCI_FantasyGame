#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "exceptions.h"

using namespace std;

//constructor
Character::Character(const string& name, int health, int gold, int armor, int magicResistance):
        name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){
    if(name.size()<1){
        throw WrongValueException("setName: ungültiger Wert für Name!");
    }
    if(health < 0 || gold < 0 || armor < 0 || magicResistance < 0){
        throw WrongValueException("Constructor: Negative Werte sind ungültig!");
    }
    memset(inventory, 0, sizeof (inventory));
}

shared_ptr<Item> Character::getInventory(int index){
        if(index < 0 || index >= INVENTORY_S){
            throw IndexException("Error: Ungültiger Index in getInventory.", index);
        }else if(!inventory[index]){
            throw EmptySlotException("Error: Ungültiger Inventar Slot in getInventory.", index);
        }else{
            return inventory[index];
        }
};

int Character::addInventarItem(shared_ptr<Item> item){
        for (int i = 0; i < INVENTORY_S; ++i) {
            if(!this->inventory[i]){
                this->inventory[i] = item;
                cout << this->inventory[i] << " wurde an Stelle " << i << " zum Inventar von " << *this << " hinzugefügt." << endl;
                return i;
            }
        }
        throw FullInventarException("Error: Inventar ist voll. Gegenstand kann nicht aufgenommen werden.");
};

shared_ptr<Item> Character::removeInventarItem(int slot) {
    if(slot < 0 || slot >= INVENTORY_S){
        throw IndexException("Error: Ungültiger Index in removeInventarItem.", slot);
    }
    else if(!inventory[slot]){
        throw EmptySlotException("Error: Ungültiger Inventar Slot in removeInventarItem.", slot);
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