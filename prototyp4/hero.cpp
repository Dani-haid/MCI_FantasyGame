#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "character.h"
#include "npc.h"
#include "exceptions.h"

using namespace std;

void Hero::attack(Character& enemy){
    //cout << "attack " << *this << endl;
    int x = 15, y = 25;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y

    int damage = rand_num - enemy.getArmor();
    if(damage > 0){
        enemy.setHealth(enemy.getHealth()-damage);
    }else{
        cout << "Angriff von " << *this << " war wirkungslos" << endl;
    }
    cout << *this << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte! "
    << enemy.getName() << " besitzt jetzt noch " << enemy.getHealth() << " Lebenspunkte." << endl;
};

void Hero::sellItem(int index){
    if(index >= 0 && index < INVENTORY_S){
        if(this->inventory[index].getIsValid()){
            this->gold += this->inventory[index].getValue();
            this->inventory[index].setIsValid(false);

            cout << "Gegenstand "<< this->inventory[index].getName() << " wird für " << this->inventory[index].getValue() <<
                 " verkauft." << *this << " besitzt nun " << this->gold << " Gold." << endl;
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
                cout << *this << " stiehlt " << enemy.getName() << " die Waffe: "
                << stolenLoot.getName() << " im Wert von " << stolenLoot.getValue() << " Gold." << endl;
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
            try{
                temp = enemy.removeInventarItem(rand_num);
            }
            catch(IndexException& e){
               cerr << e.what() <<" Eingegebener Index: " << e.getIndex() << endl;
               break;
            }

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
    if(index < 0 || index >= EQUIPMENT_S){
        throw IndexException("Error: Ungültiger Index in getEquipment.", index);
    }else if(this->equipment[index].getIsValid()){
        return this->equipment[index];
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
    if(slot < 0 || slot >= EQUIPMENT_S){
        throw IndexException("Error: Ungültiger Index in removeEquipmentItem.", slot);
    };
    if(slot >= 0 && slot < EQUIPMENT_S && this->equipment[slot].getIsValid()){
        Item tempItem = this->equipment[slot];
        this->equipment[slot].setIsValid(false);
        cout << "Gegenstand " << tempItem.getName() << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        return tempItem;
    }
    Item tempItem;
    return tempItem;
};

ostream& operator<<(ostream& out, const Hero& h){
    out << "Heldin " << h.getName();
    return out;
}