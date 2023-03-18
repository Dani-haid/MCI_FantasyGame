#include <iostream>
#include <ctime>
#include <cstdlib>
#include "item.h"
#include "hero.h"
#include "character.h"
#include "npc.h"
#include "fighter.h"
#include "sorcerer.h"


using namespace std;


int main() {

    srand(std::time(nullptr));//Damit random Number im unterschiedlich ist

    Hero annina("Annina", 300, 50, 5, 99);

    //annina.addInventarItem(new Item("Schlumpf", 20)); //wieso geht das so nicht?

    Item kanone("Kanone", 15);
    annina.addInventarItem(kanone);
    Item gummibaer("Gummibaer", 5);
    annina.addInventarItem(gummibaer);

    Fighter matthias("Matthias", 50, 0, 30, 88, 100);
    Item machete("Machete", 200);
    matthias.addInventarItem(machete);

    Sorcerer pascal("Pascal", 100, 500, 9, 77, 8);
    Item lego("Lego", 30);
    pascal.addInventarItem(lego);
    Item harpune("Harpune", 60);
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