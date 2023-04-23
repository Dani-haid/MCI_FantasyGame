#ifndef PROTOTYP5_GAME_H
#define PROTOTYP5_GAME_H

#include <map>
#include <iostream>

using namespace std;

class Character;

class Game{
private:
    map<string, Character*> characters;

public:
    //wenn kein eigener constructor definiert ist, wird der default constructor aufgerufen
    //Game(){};

    //destructor
    ~Game(){
        cout << "destructor Game " << endl;

        for (auto [key, value] : characters) {
            cout << key << " : " << value << endl;
        }

        characters.clear();
    };
    //muss ich auch alles manuell zerstören wenn ich smart pointer verwende?

    void play();

    void add(Character* character);

    void tempMapOutput();
};

#endif //PROTOTYP5_GAME_H
