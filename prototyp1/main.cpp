#include <iostream>
#include <ctime>
#include <cstdlib>
#include "hero.h"
#include "character.h"

using namespace std;


int main() {

    std::srand(std::time(nullptr));//Damit random Number im unterschiedlich ist

    struct Hero_t annina;
    initHero(&annina, (char*)"Annina", 300, 50);//wieso braucht man hier expliziten Cast?
    //wieso jetzt hier &-Zeichen und expliziter Cast von "Annina"??
    initItem(&annina.inventory[0], (char*)"Kanone", 15);
    //init Item nicht ganz verstanden wieso muss kein struct für Item zuerst erstellt werden?
    initItem(&annina.inventory[6], (char*)"Gummibär", 5);

    struct Character_t matthias;
    initCharacter(&matthias, (char*)"Matthias", 50, 0);

    struct Character_t pascal;
    initCharacter(&pascal, (char*)"Pascal", 100, 500);


    if(fight(&annina, &matthias)){//wieso hier & verwenden??
        //füge beliebigen Gegenstand im Inventar der Heldin ein
        for (int i = 0; i < 10; ++i) {
            //sizeof(annina.inventory)/sizeof(annina.inventory[0])
            // --> wollte 10 durch das ersetzen aber Fehlermeldung
            // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
            //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
            if(annina.inventory[i].isValid){
                if(i >= 10-1){
                    cout << "Inventar der Heldin ist voll!" << endl;
                    break;
                }
                continue;
            }else{
                initItem(&annina.inventory[i], (char*)"Harpune", 60);
                cout << "Gegenstand " << annina.inventory[i].name << " wurde an Stelle " << i << " zum Inventar der Heldin hinzugefügt." << endl;
                break;
            }
        }

        if(fight(&annina, &pascal)){//wieso hier & verwenden??
            //füge beliebigen Gegenstand im Inventar der Heldin ein
            for (int i = 0; i < 10; ++i) {
                if(annina.inventory[i].isValid){
                    if(i >= 10-1){
                        std::cout << "Inventar der Heldin ist voll!" << std::endl;
                        break;
                    }
                    continue;
                }else{
                    initItem(&annina.inventory[i], (char*)"Giftpfeil", 12);
                    cout << "Gegenstand " << annina.inventory[i].name << " wurde an Stelle " << i << " zum Inventar der Heldin hinzugefügt." << endl;
                    break;
                }
            }
        }

    }



    //Falls Heldin noch am Leben ist, Gegenstände verkaufen:
    if(annina.health >= 0){
        cout << "Heldin verkauft ihre Gegenstände!"<< endl;

        int count = 0;
        for (int i = 0; i < 10; ++i) {
            if(annina.inventory[i].isValid){//wird doppelt geprüft: hier und in Func SellItem
                sellItem(&annina, i);
            }else{
                count ++;
            }
        }
        if(count == sizeof(annina.inventory)/sizeof(annina.inventory[0])){
            cout << "Inventar der Heldin ist leer - nichts zu verkaufen!" << endl;
        }
    }

    return 0;
}
