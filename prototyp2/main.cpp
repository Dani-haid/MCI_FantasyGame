#include <iostream>
#include <ctime>
#include <cstdlib>
#include "hero.h"
#include "character.h"


using namespace std;


int main() {

    srand(std::time(nullptr));//Damit random Number im unterschiedlich ist

    Hero annina;
    annina.initHero("Annina", 300, 50);
    Item kanone;
    kanone.initItem("Kanone", 15);
    annina.addInventarItem(kanone);
    Item gummibaer;
    gummibaer.initItem("Gummibaer", 5);
    annina.addInventarItem(gummibaer);


    Character matthias;
    matthias.initCharacter("Matthias", 50, 0);
    Item machete;
    machete.initItem("Machete", 200);
    matthias.addInventarItem(machete);

    Character pascal;
    pascal.initCharacter("Pascal", 100, 500);
    Item lego;
    lego.initItem("Lego", 30);
    pascal.addInventarItem(lego);
    Item harpune;
    harpune.initItem("Harpune", 60);
    pascal.addInventarItem(harpune);


    if(annina.fight(matthias)){
        //Gegenstand aus dem Inventar des Charakters wird ins Inventar der Heldin übertragen
        int rand_num;//storage für welcher Slot bereits versucht wurde noch adaptieren
        int i = 0;
        Item* temp = NULL;
        while (1){
            rand_num = rand()%10; //zufälliger Slot (Zahl zwischen 0-9)
            temp = matthias.getInventory(rand_num);
            if(temp->getIsValid()){
                if(annina.addInventarItem(*temp)>=0){
                    matthias.removeInventarItem(rand_num);
                }
                break;
            }else{
                i++;
                if(i >= 100){
                    cout << "Kein Item im Inventar des Characters gefunden." << endl;
                    break;
                }continue;
            }
        }


        if(annina.fight(pascal)){
            //Gegenstand aus dem Inventar des Charakters wird ins Inventar der Heldin übertragen
            int rand_num;//storage für welcher Slot bereits versucht wurde noch adaptieren
            Item* tempT = NULL;
            int i = 0;
            while (1){
                rand_num = rand()%10; //zufälliger Slot (Zahl zwischen 0-9)
                tempT = pascal.getInventory(rand_num);
                if(tempT->getIsValid()){
                    if(annina.addInventarItem(*tempT)>=0){
                        pascal.removeInventarItem(rand_num);
                    }
                    break;
                }else{
                    i++;
                    if(i >= 100){
                        cout << "Kein Item im Inventar des Characters gefunden." << endl;
                        break;
                    }continue;
                }
            }

        }

    }else{
        cout << "Game Over!" << endl;
        exit(0);
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
