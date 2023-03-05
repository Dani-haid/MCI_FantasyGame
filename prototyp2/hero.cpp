#include <iostream>
#include "hero.h"
#include "character.h"

using namespace std;


void Hero::initHero(string name, int health, int gold){
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < INVENTORY_S ; ++i) {
        this->inventory[i].initItem();
    }
    for (int i = 0; i < EQUIPMENT_S ; ++i) {
        this->equipment->initItem();
    }

    std::cout << "Held erstellt! " << "Name: " << this->name << " Health: " << this->health << " Gold: " << this->gold << std::endl;
};


void Hero::attack(Character& enemy){
    int rand_num = rand()%((25+1)-15) + 15; //zwischen 15 und 25
    enemy.setHealth(enemy.getHealth() - rand_num);
    cout << this->name << " trifft " << enemy.getName() << " für " << rand_num << " Lebenspunkte!" << endl;
};


void Hero::sellItem(int index){
    if(index >= 0 && index < INVENTORY_S){
        if(this->inventory[index].getIsValid()){//wird aktuell doppelt geprüft
            this->gold += this->inventory[index].getValue();
            this->inventory[index].setIsValid(false);

            cout << "Gegenstand "<< this->inventory[index].getName() << " wird für " << this->inventory[index].getValue() <<
            " verkauft." << this->name << " besitzt nun " << this->gold << " Gold." << endl;
        }else{
            cout<< "kein gültiges Item vorhanden! " << endl;
        }
    }
};


bool Hero::fight(Character &enemy){
    if(this->health < 0|| enemy.getHealth() < 0){
    cout<< "Hero oder enemy haben keine Lebenspunkte mehr!" << endl;
    return false;
    }
    cout << "Neuer Kampf beginnt: " << this->name << " gegen " << enemy.getName() << endl;

    while(1){
        if(this->health < 0){
            cout << this->name << " wurde besiegt! " << enemy.getName() << " hat noch " << enemy.getHealth() << " Lebenspunkte übrig!" << endl;
            return false;
        }
        this->attack(enemy);

        if(enemy.getHealth() < 0){
            cout << enemy.getName() << " fiel in Ohnmacht! " << this->name << " hat noch " << this->health << " Lebenspunkte übrig!" << endl;
            return true;
        }
        enemy.attack(*this);
    }
};

int Hero::addInventarItem(const Item& item){
    for (int i = 0; i < INVENTORY_S; ++i) {
        //check ob der Platz im Inventar frei ist:
        if(!(this->inventory[i].getIsValid())){
            this->inventory[i] = item;
            cout << "Gegenstand " << this->inventory[i].getName() << " wurde an Stelle " << i << " zum Inventar der Heldin hinzugefügt." << endl;
            return i;
        }
    }
    std::cout << "Kein Platz mehr im Inventar der Heldin vorhanden!" << std::endl;
    return -1;
}

int Hero::addEquipmentItem(const Item& item){
    for (int i = 0; i < EQUIPMENT_S; ++i) {
        if(!(this->equipment[i].getIsValid())){
            this->equipment[i] = item;
            cout << "Gegenstand " << this->equipment[i].getName() << " wurde an Stelle " << i << " zum Equipment der Heldin hinzugefügt." << endl;
            return i;
        }
    }
    std::cout << "Kein Platz mehr im Equipment der Heldin vorhanden!" << std::endl;
    return -1;
}

Item Hero::removeInventarItem(int slot){
    Item tempItem;
    if(slot >= 0 && slot < INVENTORY_S && this->inventory[slot].getIsValid()){
        tempItem = this->inventory[slot];
        this->inventory[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Inventar der Heldin entfernt." << endl;
        return tempItem;
    }
    tempItem.initItem();
    return tempItem;
};

Item Hero::removeEquipmentItem(int slot){
    Item tempItem;
    if(slot >= 0 && slot < EQUIPMENT_S && this->equipment[slot].getIsValid()){
        tempItem = this->equipment[slot];
        this->equipment[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        return tempItem;
    }
    tempItem.initItem();
    return tempItem;
};


