#ifndef PROTOTYP5_GAME_H
#define PROTOTYP5_GAME_H

#include <map>
#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

class Character;

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

    void play();

    void addCharacter(shared_ptr<Character> character);

    void removeCharacter(const string& name);

    void addSoldItem(shared_ptr<Item> item);

    void printMapOutput();
};

#endif //PROTOTYP5_GAME_H
