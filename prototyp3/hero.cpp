#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "character.h"
#include "npc.h"

using namespace std;

void Hero::attack(Character& enemy){
    int x = 15, y = 25;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y

    int damage = rand_num - enemy.getArmor();
    if(damage > 0){
        enemy.setHealth(enemy.getHealth()-damage);
    }else{
        cout << "Angriff von " << *this << " war wirkungslos" << endl;
    }
    cout << *this << " trifft " << enemy << " für " << damage << " Lebenspunkte! "
    << enemy << " besitzt jetzt noch " << enemy.getHealth() << " Lebenspunkte." << endl;
};

void Hero::sellItem(int index){
    if(index >= 0 && index < INVENTORY_S){
        if(inventory[index].getIsValid()){
            gold += inventory[index].getValue();
            cout << inventory[index] << " wird für " << inventory[index].getValue() <<
                 " verkauft." << *this << " besitzt nun " << gold << " Gold." << endl;
            inventory[index].setIsValid(false);
        }
    }
};


bool Hero::fight(Character &enemy){
    if(this->health <= 0|| enemy.getHealth() <= 0){
        cout<< "Hero oder enemy haben keine Lebenspunkte mehr!" << endl;
        return false;
    }
    cout << "------------" << endl;
    cout << "Neuer Kampf beginnt: " << this->name << " gegen " << enemy.getName() << endl;

    while(1){
        if(this->health <= 0){
            cout << "Game Over!" << endl;
            cout << *this << " wurde besiegt! " << enemy.getName() << " hat noch " << enemy.getHealth() << " Lebenspunkte übrig!" << endl;
            return false;
        }
        this->attack(enemy);

        if(enemy.getHealth() <= 0){
            cout << enemy.getName() << " fiel in Ohnmacht! "<<
            *this << " hat noch " << this->health << " Lebenspunkte übrig!" << endl;

            Item stolenLoot = this->retrieveRandomLoot(enemy);

            if(stolenLoot.getIsValid()){
                this->addInventarItem(stolenLoot);
                cout << *this << " stiehlt " << enemy << " " << stolenLoot << " im Wert von " << stolenLoot.getValue() << " Gold." << endl;
            };
            return true;//Heldin hat Kampf gewonnen
        }

        enemy.attack(*this);
    }
};

Item Hero::retrieveRandomLoot(Character &enemy){
    //Gegenstand entfernen und zurückgeben
    int rand_num;
    int i = 0;
    Item temp;

    while (1){
        rand_num = rand()%INVENTORY_S; //zufälliger Slot (Zahl zwischen 0-9)
        temp = enemy.removeInventarItem(rand_num);

        if(temp.getIsValid()){
            return temp;
        }else{
            i++;
            if(i >= 100){
                cout << "Kein Item im Inventar des Characters gefunden." << endl;
                return temp;
            }
            continue;
        }
    }
};


Item Hero::getEquipment(int index){
    if(index >= 0 && index < EQUIPMENT_S){
        if(equipment[index].getIsValid()){
            return equipment[index];
        }
    }
    return Item();
};

int Hero::addEquipmentItem(const Item& item){
    for (int i = 0; i < EQUIPMENT_S; ++i) {
        if(!(equipment[i].getIsValid())){
            equipment[i] = item;
            cout << "Gegenstand " << equipment[i].getName() << " wurde an Stelle " << i << " zum Equipment der Heldin hinzugefügt." << endl;
            return i;
        }
    }
    std::cout << "Kein Platz mehr im Equipment der Heldin vorhanden!" << std::endl;
    return -1;
}

Item Hero::removeEquipmentItem(int slot){
    if(slot >= 0 && slot < EQUIPMENT_S && this->equipment[slot].getIsValid()){
        Item tempItem = equipment[slot];
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        equipment[slot].setIsValid(false);
        return tempItem;
    }
    return Item();
};

ostream& operator<<(ostream& out, const Hero& h){
    out << "Heldin " << h.getName();
    return out;
}