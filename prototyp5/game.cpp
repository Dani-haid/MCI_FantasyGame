#include "game.h"
//#include "character.h"
#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"

void Game::play(){
try{
    //Heldin und Gegner am Heap erstellen und Pointer in map speichern:
    //this (Game) verwaltet ownership von Characters
    shared_ptr<Hero> annina = make_shared<Hero>(this, "Annina", 300, 50, 50, 15);
    addCharacter(annina);

    //hier wird alles in Einem erstellt. Aber ich muss Annina danach mit dem Key über die map ansprechen.
    //characters.insert(make_pair("annina", new Hero("Annina", 300, 50, 50, 15)));

    shared_ptr<Fighter> matthias = make_shared<Fighter>(this, "Matthias", 50, 0, 3, 88, 100);
    addCharacter(matthias);

    shared_ptr<Sorcerer> pascal = make_shared<Sorcerer>(this, "Pascal", 100, 500, 9, 77, 8);
    addCharacter(pascal);

    //Items am Heap als SmartPointer erstellen:
    shared_ptr<Item> kanone = make_shared<Item>("Kanone", 15);
    shared_ptr<Item> gummibaer = make_shared<Item>("Gummibaer1", 5);
    shared_ptr<Item> gummibaer2 = make_shared<Item>("Gummibaer2", 35);
    shared_ptr<Item> gummibaer3 = make_shared<Item>("Gummibaer3", 8);
    shared_ptr<Item> gummibaer4 = make_shared<Item>("Gummibaer4", 3);
    shared_ptr<Item> gummibaer5 = make_shared<Item>("Gummibaer5", 55);
    shared_ptr<Item> gummibaer6 = make_shared<Item>("Gummibaer6", 94);
    shared_ptr<Item> gummibaer7 = make_shared<Item>("Gummibaer7", 1);
    shared_ptr<Item> gummibaer8 = make_shared<Item>("Gummibaer", 90);
    shared_ptr<Item> gummibaer9 = make_shared<Item>("Gummibaer", 33);
    shared_ptr<Item> gummibaer10 = make_shared<Item>("Gummibaer", 2);

    shared_ptr<Item> machete = make_shared<Item>("Machete", 200);
    shared_ptr<Item> lego = make_shared<Item>("Lego", 30);
    shared_ptr<Item> harpune = make_shared<Item>("Harpune", 60);


    annina->addInventarItem(kanone);
    annina->addInventarItem(gummibaer);
    annina->addInventarItem(gummibaer2);
    annina->addInventarItem(gummibaer3);
    annina->addInventarItem(gummibaer4);
    annina->addInventarItem(gummibaer5);
    annina->addInventarItem(gummibaer6);
    annina->addInventarItem(gummibaer7);
    annina->addInventarItem(gummibaer8);
    annina->addInventarItem(gummibaer9);
    annina->addInventarItem(gummibaer10);

    matthias->addInventarItem(machete);

    pascal->addInventarItem(lego);
    pascal->addInventarItem(harpune);

    cout << "------------" << endl;
    try{
        matthias->setGold(-30);
    }
    catch (WrongValueException& e){
        cout << e.what() << endl;
    }

/*
    //Kämpfe der Heldin
    if(!annina->fight(*matthias)){
        annina.reset();
        return 1;
    }else{
        matthias.reset();
    }
    if(!annina->fight(*pascal)){
        exit(0);
    }else{
        pascal.reset();
    }
*/

    if(annina->fight(*matthias)){
        matthias.reset();
        if(annina->fight(*pascal)){
            pascal.reset();

            //Falls Heldin noch am Leben ist, Gegenstände verkaufen:
            if(annina->getHealth() >= 0){
                cout << "Heldin verkauft ihre Gegenstände!"<< endl;
                while(1){
                    try{
                        annina->sellItem(0);
                    }
                    catch(IndexException& e){
                        cerr << e.what() <<" Eingegebener Index: " << e.getIndex() << endl;
                    }
                    catch(EmptySlotException& e){
                        cout << e.what() <<" An Stelle: " << e.getIndex() << " ist kein Gegenstand gespeichert." << endl;
                    }
                    catch(EmptyInventarException& e){
                        break;
                    }
                }
        }
    }
        cout << "------------" << endl;
    }
    annina.reset();

}
catch (WrongValueException& e){
    cerr << e.what() << endl;
}
catch (NoUniqueCharacterKeyException& e){
    cout << e.what() << endl;
}
catch (...){
    cout << "unbekannter Fehler aufgetaucht" << endl;
}

}



void Game::addCharacter(shared_ptr<Character> character){
    //überprüfung ob key unique ist, ansonsten Fehlermeldung ausgeben!!
    if(characters.find(character->getName()) == characters.end()){
        //kann beides verwendet werden
        //characters.insert(make_pair(character->getName(), character));
        characters.insert({character->getName(), character});
        //printMapOutput();
    }else{
        throw NoUniqueCharacterKeyException("Key ist bereits vorhanden. ");
    }
}

void Game::removeCharacter(const string& name){
    if(characters.find(name) != characters.end()){
        characters.erase(name);
        //printMapOutput();
    }else{
        throw NoExistingCharacterKeyException("Kein passender Key vorhanden. ");
    }
}

void Game::addSoldItem(shared_ptr<Item> item){
    soldItems.push_back(item);
    //cout << soldItems.back()->getName() << " wurde in Game Storage hinzugefügt."<< endl;
}

void Game::printMapOutput() {
    cout << "aktuelle size: " << characters.size() << endl;

    for (auto it = characters.begin(); it != characters.end(); it++) {
        cout << " Key : " << it->first
             << " , Value : " << it->second
             << endl;
    }
}
