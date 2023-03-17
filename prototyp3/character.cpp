#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"

using namespace std;


void Character::attack(Hero &hero){
    int rand_num = rand()%((15+1)-5) + 5;
    hero.setHealth(hero.getHealth() - rand_num);

    cout << this->name << " trifft " << hero.getName() << " für " << rand_num << " Lebenspunkte!" << endl;
};

Item Character::getInventory(int index){
    if(index >= 0 && index < INVENTORY_S_C){
        if(this->inventory[index].getIsValid()){
            return this->inventory[index];
        }
    }
    Item item;
    //item.initItem();
    return item;
};

int Character::addInventarItem(const Item& item){
    for (int i = 0; i < INVENTORY_S_C; ++i) {
        //check ob der Platz im Inventar frei ist:
        if(!(this->inventory[i].getIsValid())){
            this->inventory[i] = item;
            cout << "Gegenstand " << this->inventory[i].getName() << " wurde an Stelle " << i << " zum Inventar des Characters hinzugefügt." << endl;
            return i;
        }
    }
    std::cout << "Inventar ist voll!" << std::endl;
    return -1;
};

Item Character::removeInventarItem(int slot) {
    if(slot >= 0 && slot < INVENTORY_S_C && this->inventory[slot].getIsValid()){
        Item tempItem = this->inventory[slot];
        this->inventory[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Inventar des Characters entfernt." << endl;
        return tempItem;
    }
    Item tempItem;
    //tempItem.initItem();
    return tempItem;
};