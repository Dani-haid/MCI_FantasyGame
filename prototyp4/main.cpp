#include <iostream>
#include <ctime>
#include <cstdlib>
#include "item.h"
#include "hero.h"
#include "character.h"
#include "fighter.h"
#include "sorcerer.h"
#include <string>
#include "exceptions.h"
#include <memory>

using namespace std;


int main() {

    srand(std::time(nullptr));//Damit random Number im unterschiedlich ist

    Hero annina("Annina", 300, 50, 50, 15);

    Item kanone("Kanone", 15);
    cout << "Item Kanone Adresse1: "<< &kanone << endl;

    annina.addInventarItem(kanone);
    Item tempAdressItem = annina.getInventory(0);
    cout << "Item Kanone Adresse2: " << &tempAdressItem << endl;

    cout << "-----------------"<< endl;


    annina.addInventarItem(shared_ptr<Item>(new Item("TestwaffeBlubb", 99)));

    cout << "-----------------"<< endl;

    Item gummibaer("Gummibaer", 5);
    annina.addInventarItem(gummibaer);

    Fighter matthias("Matthias", 50, 0, 3, 88, 100);
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
    };


    /*
    //-----Test von try catch------ throw in character getInventory
    try{
    Item testItem1 = annina.getInventory(4);
    cout << "Testitem von getInventory: " << testItem1.getName() << endl;

    Item testItem2 = annina.getInventory(13);
    cout << "Testitem von getInventory: " << testItem2.getName() << endl;
    }
    catch(string& s){
        cerr << s << endl;
    }
    catch(IndexException& e){
        cerr << e.what() <<" Eingegebener Index: " << e.getIndex() << endl;
    }
    catch(...){
        cerr << "Unbekannter Fehler" <<endl;
        exit(1);
    }
     */


    //Falls Heldin noch am Leben ist, Gegenstände verkaufen:
    if(annina.getHealth() >= 0){
        cout << "------------" << endl;
        cout << "Heldin verkauft ihre Gegenstände!"<< endl;
        for (int i = 0; i < INVENTORY_S; ++i) {
            try{
                //annina.sellItem(14);
                annina.sellItem(i);
            }
            catch(IndexException& e){
                cerr << e.what() <<" Eingegebener Index: " << e.getIndex() << endl;
            }
            catch(...){
                cerr << "Unbekannter Fehler" <<endl;
            }
        }
        cout << "------------" << endl;
    }

    return 0;
}