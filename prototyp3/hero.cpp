#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "character.h"

using namespace std;

void Hero::attack(Character& enemy){
    int rand_num = rand()%((25+1)-15) + 15; //zwischen 15 und 25
    enemy.setHealth(enemy.getHealth() - rand_num);
    cout << this->name << " trifft " << enemy.getName() << " für " << rand_num << " Lebenspunkte!" << endl;
};

void Hero::sellItem(int index){
    if(index >= 0 && index < INVENTORY_S){
        if(this->inventory[index].getIsValid()){
            this->gold += this->inventory[index].getValue();
            this->inventory[index].setIsValid(false);

            cout << "Gegenstand "<< this->inventory[index].getName() << " wird für " << this->inventory[index].getValue() <<
                 " verkauft." << this->name << " besitzt nun " << this->gold << " Gold." << endl;
        }
    }
};


bool Hero::fight(Character &enemy){
    if(this->health <= 0|| enemy.getHealth() <= 0){
        cout<< "Hero oder enemy haben keine Lebenspunkte mehr!" << endl;
        return false;
    }
    cout << "Neuer Kampf beginnt: " << this->name << " gegen " << enemy.getName() << endl;

    while(1){
        if(this->health <= 0){
            cout << this->name << " wurde besiegt! " << enemy.getName() << " hat noch " << enemy.getHealth() << " Lebenspunkte übrig!" << endl;
            cout << "Game Over!" << endl;
            return false;
        }
        this->attack(enemy);

        if(enemy.getHealth() <= 0){
            cout << enemy.getName() << " fiel in Ohnmacht! " << this->name << " hat noch " << this->health << " Lebenspunkte übrig!" << endl;

            int rand_num;
            int i = 0;
            Item temp;
            while (1){
                rand_num = rand()%INVENTORY_S; //zufälliger Slot (Zahl zwischen 0-9)
                temp = enemy.removeInventarItem(rand_num);
                if(temp.getIsValid()){
                    this->addInventarItem(temp);
                    break;
                }else{
                    i++;
                    if(i >= 100){
                        cout << "Kein Item im Inventar des Characters gefunden." << endl;
                        break;
                    }continue;
                }
            }
            return true;
        }

        enemy.attack(*this);
    }
};

Item Hero::getInventory(int index){
    if(index >= 0 && index < INVENTORY_S){
        if(this->inventory[index].getIsValid()){
            return this->inventory[index];
        }
    }
    Item item;
    return item;
};

Item Hero::getEquipment(int index){
    if(index >= 0 && index < EQUIPMENT_S){
        if(this->equipment[index].getIsValid()){
            return this->equipment[index];
        }
    }
    Item item;
    return item;
};

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

Item Hero::removeEquipmentItem(int slot){
    if(slot >= 0 && slot < EQUIPMENT_S && this->equipment[slot].getIsValid()){
        Item tempItem = this->equipment[slot];
        this->equipment[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        return tempItem;
    }
    Item tempItem;
    return tempItem;
};