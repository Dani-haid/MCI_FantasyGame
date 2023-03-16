#include <iostream>
#include <ctime>
#include <cstdlib>
#include "item.h"
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


    if(!annina.fight(matthias)){
        exit(0);
    }
    if(!annina.fight(pascal)){
        exit(0);
    }


    //Falls Heldin noch am Leben ist, Gegenstände verkaufen:
    if(annina.getHealth() >= 0){
        cout << "Heldin verkauft ihre Gegenstände!"<< endl;
        for (int i = 0; i < INVENTORY_S; ++i) {
            annina.sellItem(i);
        }
    }

    return 0;
}