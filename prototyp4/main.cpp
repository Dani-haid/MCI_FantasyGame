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

    //Heldin und Gegner erstellen:
    Hero annina("Annina", 300, 50, 50, 15);
    Fighter matthias("Matthias", 50, 0, 3, 88, 100);
    Sorcerer pascal("Pascal", 100, 500, 9, 77, 8);

    //Items am Heap als SmartPointer erstellen:
    shared_ptr<Item> kanone = make_shared<Item>("Kanone", 15);
    shared_ptr<Item> gummibaer = make_shared<Item>("Gummibaer1", 5);
    shared_ptr<Item> gummibaer2 = make_shared<Item>("Gummibaer2", 5);
    shared_ptr<Item> gummibaer3 = make_shared<Item>("Gummibaer3", 5);
    shared_ptr<Item> gummibaer4 = make_shared<Item>("Gummibaer4", 5);
    shared_ptr<Item> gummibaer5 = make_shared<Item>("Gummibaer5", 5);
    shared_ptr<Item> gummibaer6 = make_shared<Item>("Gummibaer6", 5);
    shared_ptr<Item> gummibaer7 = make_shared<Item>("Gummibaer7", 5);
    shared_ptr<Item> gummibaer8 = make_shared<Item>("Gummibaer", 5);
    shared_ptr<Item> gummibaer9 = make_shared<Item>("Gummibaer", 5);
    shared_ptr<Item> gummibaer10 = make_shared<Item>("Gummibaer", 5);
    //andere Option ohne make_shared:
    // annina.addInventarItem(std::shared_ptr<Item>(new Item("abc", 495)));

    shared_ptr<Item> machete = make_shared<Item>("Machete", 200);
    shared_ptr<Item> lego = make_shared<Item>("Lego", 30);
    shared_ptr<Item> harpune = make_shared<Item>("Harpune", 60);

    //Items in die jeweiligen Inventare hinzufügen
        try{
            annina.addInventarItem(kanone);
            annina.addInventarItem(gummibaer);
            annina.addInventarItem(gummibaer2);
            annina.addInventarItem(gummibaer3);
            annina.addInventarItem(gummibaer4);
            annina.addInventarItem(gummibaer5);
            annina.addInventarItem(gummibaer6);
            //annina.addInventarItem(gummibaer7);
            //annina.addInventarItem(gummibaer8);
            //annina.addInventarItem(gummibaer9);
            //annina.addInventarItem(gummibaer10);
        }
        catch (FullInventarException e){
            cerr << e.what() << " Heldin hat keinen Platz mehr im Rucksack!" << endl;
        }
        try{
            matthias.addInventarItem(machete);
        }
        catch (FullInventarException e){
            cerr << e.what() << endl;
        }
        try{
        pascal.addInventarItem(lego);
        pascal.addInventarItem(harpune);
        }
        catch (FullInventarException e){
        cerr << e.what() << endl;
        }


    //Kämpfe der Heldin
    if(!annina.fight(matthias)){
        exit(0);
    }
    if(!annina.fight(pascal)){
        exit(0);
    };


    //Falls Heldin noch am Leben ist, Gegenstände verkaufen:
    if(annina.getHealth() >= 0){
        cout << "------------" << endl;
        cout << "Heldin verkauft ihre Gegenstände!"<< endl;
        for (int i = 0; i < INVENTORY_S; ++i) {
            try{
                annina.sellItem(i);
            }
            catch(IndexException& e){
                cerr << e.what() <<" Eingegebener Index: " << e.getIndex() << endl;
            }
            catch(EmptySlotException e){
                cerr << e.what() <<" An Stelle: " << e.getIndex() << " ist kein Gegenstand gespeichert." << endl;
            }
            catch(...){
                cerr << "Unbekannter Fehler" <<endl;
            }
        }
        cout << "------------" << endl;
    }

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


    return 0;
}