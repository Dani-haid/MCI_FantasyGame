#include <cstring>
//#include <cstdlib>
#include <iostream>
#include "character.h"
#include "hero.h"

using namespace std;

void initCharacter(Character_t* character, char* name, int health, int gold){
    strcpy(character->name, name);
    character->health = health;
    character->gold = gold;

    for (int i = 0; i < 10 ; ++i) {
        //sizeof(character->inventory)/sizeof(character->inventory[0])
        // --> wollte 10 durch das ersetzen aber Fehlermeldung
        // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
        //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
        initItem(&character->inventory[i]);
    }
    //std::cout << "Charakter erstellt! " << "Name: " << character->name << " Health: " <<character->health << " Gold: " << character->gold << std::endl;
};

void attack(Character_t* character, Hero_t* hero){
    int rand_num = std::rand()%((15+1)-5) + 5;
    hero->health -= rand_num;

    cout << character->name << " trifft " << hero->name << " für " << rand_num << " Lebenspunkte!" << endl;
}
