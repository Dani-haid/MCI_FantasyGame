#ifndef PROTOTYP5_GAME_H
#define PROTOTYP5_GAME_H

#include <map>
#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

class Character;
class Hero;
class Fighter;
class Sorcerer;

class Game{
protected:
    map<string, shared_ptr<Character>> characters; //Pointer auf erstellte Character
    vector<shared_ptr<Item>> soldItems; //Gegenstände, die sich nicht im Inventar eines Charakters befinden

public:
    //wenn kein eigener constructor definiert ist, wird der default constructor aufgerufen
    //Game(){};

    //destructor
    ~Game(){
        cout << "destructor Game " << endl;

        /*for (auto it = characters.begin(); it != characters.end(); it++) {
            cout << " Key : " << it->first
                 << " , Value : " << it->second
                 << endl;
        }*/
    };

    shared_ptr<Hero> createHero(const string& name, int health, int gold, int armor, int magicResistance);
    shared_ptr<Fighter> createFighter(const string& name, int health, int gold, int armor, int magicResistance, int strength);
    shared_ptr<Sorcerer> createSorcerer(const string& name, int health, int gold, int armor, int magicResistance, int magicPower);

    void play();

    void addCharacter(shared_ptr<Character> character);

    void removeCharacter(const string& name);

    void addSoldItem(shared_ptr<Item> item);

    bool fight(shared_ptr<Character> enemy1, shared_ptr<Character> enemy2);

    void printMapOutput();
};

#endif //PROTOTYP5_GAME_H
