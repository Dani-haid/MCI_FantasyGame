#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "character.h"
#include "npc.h"
#include "exceptions.h"

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
    cout << *this << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte! "
    << enemy.getName() << " besitzt jetzt noch " << enemy.getHealth() << " Lebenspunkte." << endl;
};

void Hero::sellItem(int index){
        if(index < 0 || index >= INVENTORY_S) {
            throw IndexException("Ungültiger Index in sellItem.", index);
        } else if(!this->inventory[index]){
            throw EmptySlotException("Leerer Inventar Slot in sellItem.", index);
        }else{
            this->gold += this->inventory[index]->getValue();
            cout << "Gegenstand "<< this->inventory[index]->getName() << " wird für " << this->inventory[index]->getValue() <<
                 " verkauft." << *this << " besitzt nun " << this->gold << " Gold." << endl;
            this->inventory[index].reset();
        }
};


bool Hero::fight(Character &enemy){
    if(this->health <= 0|| enemy.getHealth() <= 0){
        cout<< "Hero oder enemy haben keine Lebenspunkte mehr!" << endl;
        return false;
    }
    cout << "------------" << endl;
    cout << "Neuer Kampf beginnt: " << this->name << " gegen " << enemy.getName() << endl;

    while(this->getHealth() > 0 && enemy.getHealth() > 0){
        this->attack(enemy); //Heldin greift Gegner an

        if(enemy.getHealth() <= 0){
            cout << enemy.getName() << " fiel in Ohnmacht! "<<
                 *this << " hat noch " << this->health << " Lebenspunkte übrig!" << endl;

            shared_ptr<Item> stolenLoot = this->retrieveRandomLoot(enemy);
            if(stolenLoot){
                if(this->addInventarItem(stolenLoot) > 0){
                    cout << *this << " stiehlt " << enemy.getName() << " die Waffe: "
                         << stolenLoot->getName() << " im Wert von " << stolenLoot->getValue() << " Gold." << endl;
                }
            };
            return true;//Heldin hat Kampf gewonnen
        }
        enemy.attack(*this);
    }
    cout << "Game Over!" << endl;
    cout << *this << " wurde besiegt! " << enemy.getName() << " hat noch " << enemy.getHealth() << " Lebenspunkte übrig!" << endl;
    return false;



};

shared_ptr<Item> Hero::retrieveRandomLoot(Character &enemy){
    //Gegenstand entfernen und zurückgeben
    int rand_num;
    int i = 0;
    shared_ptr<Item> temp = nullptr;
    make_shared<Item>();//??


        while (1){
            //rand_num = 8;//testvariable
            rand_num = rand()%INVENTORY_S; //zufälliger Slot (Zahl zwischen 0-9)

            try{
                temp = enemy.removeInventarItem(rand_num);

                if(temp){
                    return temp;
                }else{
                    i++;
                    if(i >= 100){
                        throw NoItemFoundException(" Kein Item im Inventar des Characters gefunden.");
                    }
                    continue;
                }
            }
            catch(IndexException& e){
                cerr << "RetrieveRandomLoot: " << enemy.getName() << " " << e.what() <<" Eingegebener Index: " << e.getIndex() << endl;
                break;
            }
            catch(EmptySlotException& e){
                cout << e.what() <<" An Stelle: " << e.getIndex() << " ist kein Gegenstand gespeichert." << endl;
            }
            catch(NoItemFoundException& e){
                cerr << "RetrieveRandomLoot: " << enemy.getName() << e.what() << endl;
                return temp;
            }
        }
        return temp;
};


shared_ptr<Item> Hero::getEquipment(int index){
    try {
        if (index < 0 || index >= EQUIPMENT_S) {
            throw IndexException("Error: Ungültiger Index in getEquipment.", index);
        } else if (!this->equipment[index]) {
            throw EmptySlotException("Error: Ungültiger Inventar Slot in getEquipment. Hier ist kein Gegenstand gespeichert!", index);
        } else {
            return this->equipment[index];
        }
    }
    catch (EmptySlotException& e){
        cout << e.what() <<" An Stelle: " << e.getIndex() << " ist kein Gegenstand gespeichert." << endl;
        this->equipment[index].reset();
        return this->equipment[index];
    }
};

int Hero::addEquipmentItem(const shared_ptr<Item> item){
    for (int i = 0; i < EQUIPMENT_S; ++i) {
        if(!this->equipment[i]){
            this->equipment[i] = item; //hä?
            //cout << "Gegenstand " << this->equipment[i]->getName() << " wurde an Stelle " << i << " zum Equipment der Heldin hinzugefügt." << endl;
            return i;
        }
    }
    throw FullInventarException("Error: Inventar ist voll in addEquipmentItem.");
}

shared_ptr<Item> Hero::removeEquipmentItem(int slot){
    if(slot < 0 || slot >= EQUIPMENT_S){
        throw IndexException("Error: Ungültiger Index in removeEquipmentItem.", slot);
    }else if(!this->equipment[slot]){
        return nullptr;
        //throw EmptySlotException("Error: Ungültiger Inventar Slot in removeEquipmentItem.", slot);
    }else{
        shared_ptr<Item> tempItem = this->equipment[slot];
        cout << "Gegenstand " << tempItem->getName() << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        this->equipment[slot].reset();
        return tempItem;
    }
};

ostream& operator<<(ostream& out, const Hero& h){
    out << "Heldin " << h.getName();
    return out;
}