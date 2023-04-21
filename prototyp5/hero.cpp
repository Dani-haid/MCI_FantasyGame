#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "character.h"
#include "npc.h"
#include "exceptions.h"

using namespace std;

//constructor
Hero::Hero(const string& name, int health, int gold, int armor, int magicResistance):
        Character(name, health, gold, armor, magicResistance){
    memset(equipment, 0, sizeof (equipment));
    cout << *this << " erstellt" << endl;
}

//destructor
Hero::~Hero(){
    cout << *this << " verabschiedet sich in den Sonnenuntergang." << endl;
};

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
        if(index < 0) {
            throw IndexException("Ungültiger Index in sellItem.", index);
        } else if(!inventory[index]) {
            throw EmptySlotException("Leerer Inventar Slot in sellItem.", index);
        }
        else if(index >= inventory.size()){
            throw EmptyInventarException("Inventar ist leer in sellItem.");
        }
        else{
            gold += inventory[index]->getValue();
            cout << inventory[index] << " wird für " << inventory[index]->getValue() <<
                 " verkauft. " << *this << " besitzt nun " << gold << " Gold." << endl;
            inventory.erase(inventory.begin()+index);
        }
};


bool Hero::fight(Character &enemy){
    if(health <= 0|| enemy.getHealth() <= 0){
        cout<< "Hero oder enemy haben keine Lebenspunkte mehr!" << endl;
        return false;
    }
    cout << "------------" << endl;
    cout << "Neuer Kampf beginnt: " << *this << " gegen " << enemy << endl;

    while(health > 0 && enemy.getHealth() > 0) {
        this->attack(enemy); //Heldin greift Gegner an
        if (enemy.getHealth() > 0) {
            enemy.attack(*this);
        }
    }

        if(enemy.getHealth() <= 0) {
            cout << enemy << " fiel in Ohnmacht! " << *this << " hat noch " << health << " Lebenspunkte übrig!" << endl;

            try {
                //Wenn es einen gültigen Gegenstand gibt wird dies ausgeführt, sonst gibt es exception
                shared_ptr<Item> stolenLoot = this->retrieveRandomLoot(enemy);
                //Wenn es einen gültigen Gegenstand gibt wird dies ausgeführt, sonst gibt es exception
                this->addInventarItem(stolenLoot);
                cout << *this << " stiehlt " << enemy << " " << stolenLoot << " im Wert von "
                << stolenLoot->getValue() << " Gold." << endl;
            } catch(FullInventarException& e){
                cout << "fight: " << e.what() << endl;
            }
            catch (NoItemFoundException& e){
                cout << "fight: " << enemy << e.what() << endl;
            }
            return true;//Heldin hat Kampf gewonnen
        }else{
            cout << "Game Over!" << endl;
            cout << *this << " wurde besiegt! " << enemy << " hat noch " << enemy.getHealth() << " Lebenspunkte übrig!" << endl;
            return false;//Heldin hat Kampf verloren
        }
};

shared_ptr<Item> Hero::retrieveRandomLoot(Character &enemy){
    //Gegenstand entfernen und zurückgeben
    int rand_num;
    shared_ptr<Item> temp = nullptr;

    for(int i = 0; i <= 30; i++){
        //rand_num = 8;//testvariable
        rand_num = rand() % 10; //zufälliger Slot (Zahl zwischen 0-9)

        try{
            temp = enemy.removeInventarItem(rand_num);
            return temp;
        }
        catch (EmptySlotException& e){
        }
        catch(EmptyInventarException& e){
        }
    }
    throw NoItemFoundException(" Kein Item im Inventar des Characters gefunden.");
};


shared_ptr<Item> Hero::getEquipment(int index){
        if (index < 0 || index >= EQUIPMENT_S) {
            throw IndexException("Error: Ungültiger Index in getEquipment.", index);
        } else if (!equipment[index]) {
            throw EmptySlotException("Error: Ungültiger Inventar Slot in getEquipment. Hier ist kein Gegenstand gespeichert!", index);
        } else {
            return equipment[index];
        }
};

int Hero::addEquipmentItem(const shared_ptr<Item> item){
    for (int i = 0; i < EQUIPMENT_S; ++i) {
        if(!equipment[i]){
            equipment[i] = item; //hä?
            //cout << "Gegenstand " << equipment[i]->getName() << " wurde an Stelle " << i << " zum Equipment der Heldin hinzugefügt." << endl;
            return i;
        }
    }
    throw FullInventarException("Error: Inventar ist voll in addEquipmentItem.");
}

shared_ptr<Item> Hero::removeEquipmentItem(int slot){
    if(slot < 0 || slot >= EQUIPMENT_S){
        throw IndexException("Error: Ungültiger Index in removeEquipmentItem.", slot);
    }else if(!equipment[slot]){
        return shared_ptr<Item>();//korrekt?
        //throw EmptySlotException("Error: Ungültiger Inventar Slot in removeEquipmentItem.", slot);
    }else{
        shared_ptr<Item> tempItem = equipment[slot];
        cout << "Gegenstand " << tempItem << " an Stelle " << slot << " wurde aus dem Equipment der Heldin entfernt." << endl;
        equipment[slot].reset();
        return tempItem;
    }
};

ostream& operator<<(ostream& out, const Hero& h){
    out << "Heldin " << h.getName();
    return out;
}