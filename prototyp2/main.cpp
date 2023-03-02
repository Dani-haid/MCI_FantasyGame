#include <iostream>
#include <string> //wo genau inkludieren?
#include <ctime>
#include <cstdlib>
#include "hero.h"
#include "character.h"


using namespace std;


int main() {

    std::srand(std::time(nullptr));//Damit random Number im unterschiedlich ist

    Hero annina;
    annina.initHero("Annina", 300, 50);

    //annina.inventory->initItem("Kanone", 15);
    //annina.inventory->initItem("Gummibär", 5);

    annina.getInventory(0)->initItem("Kanone", 15);
    annina.getInventory(1)->initItem("Gummibär", 5);
    cout << "Gegenstand " << annina.getInventory(0)->getName() << " wurde zum Inventar der Heldin hinzugefügt." << endl;
    cout << "Gegenstand " << annina.getInventory(1)->getName() << " wurde zum Inventar der Heldin hinzugefügt." << endl;


    Character matthias;
    matthias.initCharacter("Matthias", 50, 0);

    Character pascal;
    pascal.initCharacter("Pascal", 100, 500);


    if(annina.fight(matthias)){
        //füge beliebigen Gegenstand im Inventar der Heldin ein
        for (int i = 0; i < 10; ++i) {
            //sizeof(annina.inventory)/sizeof(annina.inventory[0])
            // --> wollte 10 durch das ersetzen aber Fehlermeldung
            // error: comparison of integer expressions of different signedness: 'int' and 'long unsigned int'
            //prüfen ob Plätze im Inventar bereits voll sind (isValid true?)
            if(annina.getInventory(i)->getIsValid()){
                if(i >= 10-1){
                    cout << "Inventar der Heldin ist voll!" << endl;
                    break;
                }
                continue;
            }else{
                annina.getInventory(i)->initItem("Harpune", 60);
                cout << "Gegenstand " << annina.getInventory(i)->getName() << " wurde an Stelle " << i << " zum Inventar der Heldin hinzugefügt." << endl;
                break;
            }
        }

        if(annina.fight(pascal)){
            //füge beliebigen Gegenstand im Inventar der Heldin ein
           for (int i = 0; i < 10; ++i) {
                if(annina.getInventory(i)->getIsValid()){
                    if(i >= 10-1){
                        std::cout << "Inventar der Heldin ist voll!" << std::endl;
                        break;
                    }
                    continue;
                }else{
                    annina.getInventory(i)->initItem("Giftpfeil", 12);
                    cout << "Gegenstand " << annina.getInventory(i)->getName() << " wurde an Stelle " << i << " zum Inventar der Heldin hinzugefügt." << endl;
                    break;
                }
            }
        }

    }


    //Falls Heldin noch am Leben ist, Gegenstände verkaufen:
   if(annina.getHealth() >= 0){
        cout << "Heldin verkauft ihre Gegenstände!"<< endl;

        int count = 0;

        for (int i = 0; i < 10; ++i) {
            if(annina.getInventory(i)->getIsValid()){//wird doppelt geprüft: hier und in Func SellItem
                annina.sellItem(i);
            }else{
                count ++;
            }
        }
        //muss gecheckt werden!!
        if(count == sizeof(annina.getInventory(10))/sizeof(annina.getInventory(0))){
            cout << "Inventar der Heldin ist leer - nichts zu verkaufen!" << endl;
        }
    }


    return 0;
}
