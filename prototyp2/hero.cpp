#include <iostream>
#include "hero.h"
#include "character.h"

using namespace std;

void Hero::initHero(string name, int health, int gold){
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < 10 ; ++i) {
        //sizeof(hero->inventory)/sizeof(hero->inventory[0]
        // --> wollte 10 durch das ersetzen aber Fehlermeldung
        // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
        //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
        this->inventory[i].initItem();
    }
    for (int i = 0; i < 2 ; ++i) {
        //sizeof(hero->equipment)/sizeof(hero->equipment[0])
        // --> wollte 2 durch das ersetzen aber Fehlermeldung
        // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
        //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
        this->equipment->initItem();
    }

    std::cout << "Held erstellt! " << "Name: " << this->name << " Health: " << this->health << " Gold: " << this->gold << std::endl;
};


void Hero::attack(Character &enemy){
    //hier wird Referenz benötigt weil sonst nur kopie des wertes und dann ist geänderter Health nach Ende der Funktion wieder beim alten.
    int rand_num = std::rand()%((25+1)-15) + 15; //zwischen 15 und 25
    int newHealth = enemy.getHealth() - rand_num; //umständlich geschrieben - noch vereinfachen!!
    enemy.setHealth(newHealth);
    cout << this->name << " trifft " << enemy.getName() << " für " << rand_num << " Lebenspunkte!" << endl;
};


void Hero::sellItem(int index){
    if(this->inventory[index].getIsValid()){//wird aktuell doppelt geprüft
        this->gold += this->inventory[index].getValue();

    cout << "Gegenstand "<< this->inventory[index].getName() <<
    " wird für " << this->inventory[index].getValue() << " verkauft." << this->name << " besitzt nun " << this->gold << " Gold." << endl;

        this->inventory[index].setIsValid(false);
    }else{
        cout<< "kein gültiges Item vorhanden! " << endl;
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
        enemy.attack(*this); //wieso hier nun * ??
    }
};

int Hero::addInventarItem(const Item& item){
    for (int i = 0; i < 10; ++i) {
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
    for (int i = 0; i < 2; ++i) {
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
    if(slot >= 0 && slot < 10 && this->inventory[slot].getIsValid()){
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
    if(slot >= 0 && slot < 2 && this->equipment[slot].getIsValid()){
        tempItem = this->equipment[slot];
        this->equipment[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        return tempItem;
    }
    tempItem.initItem();
    return tempItem;
};





//getter:
string Hero::getName(){
    return name;
}
int Hero::getHealth(){
    return health;
}
int Hero::getGold(){
    return gold;
}

Item* Hero::getInventory(int index){
    //prüfen wenn index < 0 oder > 10 ist
    return &this->inventory[index];
}

Item* Hero::getEquipment(int index){
    return &this->equipment[index];
};

//setter:
void Hero::setName(string name){
    this->name = name;
}
void Hero::setHealth(int health){
    this->health = health;
}
void Hero::setGold(int gold){
    if(gold > 0){
        this->gold = gold;
    }
}
