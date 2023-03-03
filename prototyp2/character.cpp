#include <iostream>
#include "character.h"
#include "hero.h"

using namespace std;

void Character::initCharacter(string name, int health, int gold){
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < 10 ; ++i) {
        //sizeof(character->inventory)/sizeof(character->inventory[0])
        // --> wollte 10 durch das ersetzen aber Fehlermeldung
        // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
        //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
        this->inventory[i].initItem();
    }
    std::cout << "Charakter erstellt! " << "Name: " << this->name << " Health: " << this->health << " Gold: " << this->gold << std::endl;
};

void Character::attack(Hero &hero){
    int rand_num = std::rand()%((15+1)-5) + 5;
    int newHealth = hero.getHealth() - rand_num;
    hero.setHealth(newHealth);
    //hero.health -= rand_num;

    cout << this->name << " trifft " << hero.getName() << " für " << rand_num << " Lebenspunkte!" << endl;
};

int Character::addInventarItem(const Item& item){
    for (int i = 0; i < 10; ++i) {
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
    Item tempItem;
    if(slot >= 0 && slot < 10 && this->inventory[slot].getIsValid()){
        tempItem = this->inventory[slot];
        this->inventory[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Inventar des Characters entfernt." << endl;
        return tempItem;
    }
    tempItem.initItem();
    return tempItem;
}

//getter:
string Character::getName(){
    return name;
}

int Character::getHealth(){
    return health;
}

int Character::getGold(){
    return gold;
}

Item* Character::getInventory(int index){
    return &this->inventory[index];
};

//setter:
void Character::setName(string name){
    this->name = name;
};

void Character::setHealth(int health){
    //hier wird health aktuell ins negative gesetzt, soll ich das zulassen?
    this->health = health;
/*        if(health > 0){
            this->health = health;
        }
        this->health = 0;*/
};

void Character::setGold(int gold){
    if(gold > 0){
        this->gold = gold;
    }
};
