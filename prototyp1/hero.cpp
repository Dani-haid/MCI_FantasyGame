#include <cstring>
//#include <cstdlib>
#include <iostream>
#include "hero.h"
#include "character.h"

using namespace std;

void initHero(Hero_t* hero, char* name, int health, int gold){
    strcpy(hero->name, name);
    hero->health = health;
    hero->gold = gold;

    for (int i = 0; i < 10 ; ++i) {
        //sizeof(hero->inventory)/sizeof(hero->inventory[0]
        // --> wollte 10 durch das ersetzen aber Fehlermeldung
        // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
        //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
        initItem(&hero->inventory[i]); //wieso & Operator?
    }
    for (int i = 0; i < 2 ; ++i) {
        //sizeof(hero->equipment)/sizeof(hero->equipment[0])
        // --> wollte 2 durch das ersetzen aber Fehlermeldung
        // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
        //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
        initItem(&hero->equipment[i]);
    }

    //std::cout << "Held erstellt! " << "Name: " << hero->name << " Health: " <<hero->health << " Gold: " << hero->gold << std::endl;
};


void attack(Hero_t* hero, Character_t* enemy){
    int rand_num = std::rand()%((25+1)-15) + 15;
    enemy->health -= rand_num;
    cout << hero->name << " trifft " << enemy->name << " für " << rand_num << " Lebenspunkte!" << endl;
};


void sellItem(Hero_t* hero, int index){
    if(hero->inventory[index].isValid){//wird aktuell doppelt geprüft
    hero->gold += hero->inventory[index].value;

    cout << "Gegenstand "<< hero->inventory[index].name <<
    " wird für " << hero->inventory[index].value << " verkauft." << hero->name << " besitzt nun " << hero->gold << " Gold." << endl;

    hero->inventory[index].isValid = false;
    }else{
        cout<< "kein gültiges Item vorhanden! " << endl;
    }
};


bool fight(Hero_t* hero, Character_t* enemy){
    if(hero->health < 0|| enemy->health < 0){
    cout<< "Hero oder enemy haben keine Lebenspunkte mehr!" << endl;
    return false;
    }
    cout << "Neuer Kampf beginnt: " << hero->name << " gegen " << enemy->name << endl;

    while(1){
        if(hero->health < 0){
            cout << hero->name << " wurde besiegt! " << enemy->name << " hat noch " << enemy->health << " Lebenspunkte übrig!" << endl;
            return false;
        }
        attack(hero, enemy);

        if(enemy->health < 0){
            cout << enemy->name << " fiel in Ohnmacht! " << hero->name << " hat noch " << hero->health << " Lebenspunkte übrig!" << endl;
            return true;
        }
        attack(enemy, hero);
    }
};
