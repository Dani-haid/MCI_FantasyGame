#include "game.h"
//#include "character.h"
#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"
#include "exceptions.h"

void Game::play(){
try{
    //Heldin und Gegner am Heap erstellen und Pointer in map speichern:
    //this (Game) verwaltet ownership von Characters
    shared_ptr<Hero> annina = createHero("Annina", 300, 50, 50, 15);
    shared_ptr<Fighter> matthias = createFighter("Matthias", 50, 0, 3, 88, 100);
    shared_ptr<Sorcerer> pascal = createSorcerer("Pascal", 100, 500, 9, 77, 8);

    //hier wird alles in Einem erstellt. Aber ich muss Annina danach mit dem Key über die map ansprechen.
    //characters.insert(make_pair("annina", new Hero("Annina", 300, 50, 50, 15)));

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
    pascal->addInventarItem(make_shared<Item>("Leiter", 50));

    if(fight(annina, matthias)){
        matthias.reset();
        if(fight(annina, pascal)){
            pascal.reset();

            //Falls Heldin noch am Leben ist, Gegenstände verkaufen:
            if(annina->getHealth() >= 0){
                cout << "Heldin verkauft ihre Gegenstände!"<< endl;
                annina->sellAllItems();
        }
    }
        cout << "------------" << endl;
    }
    cout << "Game Over!" << endl;
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

shared_ptr<Hero> Game::createHero(const string &name, int health, int gold, int armor, int magicResistance) {
    if(characters.find(name) != characters.end()){
        throw NoUniqueCharacterKeyException("Key bereits vorhanden. ");
    }else{
        auto c = make_shared<Hero>(this, name, health, gold, armor, magicResistance);
        characters.insert({name, c});
        return c;
    }
};

shared_ptr<Fighter> Game::createFighter(const string &name, int health, int gold, int armor, int magicResistance,
                    int strength) {
    if(characters.find(name) != characters.end()){
        throw NoUniqueCharacterKeyException("Key bereits vorhanden. ");
    }else{
        auto c = make_shared<Fighter>(this, name, health, gold, armor, magicResistance, strength);
        characters.insert({name, c});
        return c;
    }
}

shared_ptr<Sorcerer> Game::createSorcerer(const string &name, int health, int gold, int armor, int magicResistance,
                     int magicPower) {
    if(characters.find(name) != characters.end()){
        throw NoUniqueCharacterKeyException("Key bereits vorhanden. ");
    }else{
        auto c = make_shared<Sorcerer>(this, name, health, gold, armor, magicResistance, magicPower);
        characters.insert({name, c});
        return c;
    }
}

bool Game::fight(shared_ptr<Character> enemy1, shared_ptr<Character> enemy2){
    if(enemy1->getHealth() <= 0|| enemy2->getHealth() <= 0){
        cout<< "Hero oder enemy haben keine Lebenspunkte mehr!" << endl;
        return false;
    }
    cout << "------------" << endl;
    cout << "Neuer Kampf beginnt: " << *enemy1 << " gegen " << *enemy2 << endl;

    while(enemy1->getHealth() > 0 && enemy2->getHealth() > 0) {
        enemy1->attack(enemy2);
        if (enemy2->getHealth() > 0) {
            enemy2->attack(enemy1);
        }
    }

    shared_ptr<Character> winner;
    shared_ptr<Character> loser;

    if(enemy1->getHealth() <= 0) {
        loser = enemy1;
        winner = enemy2;
    }else{
        loser = enemy2;
        winner = enemy1;
    }
    cout << *loser << " fiel in Ohnmacht! " << *winner << " hat noch " << winner->getHealth() << " Lebenspunkte übrig!" << endl;
    shared_ptr<Npc> npc = dynamic_pointer_cast<Npc>(loser);
    if(npc){
        try {
            //Wenn es einen gültigen Gegenstand gibt wird dies ausgeführt, sonst gibt es exception
            shared_ptr<Item> stolenLoot = npc->retrieveRandomLoot();
            //Wenn es einen gültigen Gegenstand gibt wird dies ausgeführt, sonst gibt es exception
            winner->addInventarItem(stolenLoot);
            cout << *winner << " stiehlt " << *loser << " " << stolenLoot << " im Wert von " << stolenLoot->getValue() << " Gold." << endl;
            }
            catch (NoItemFoundException& e){
                cout << "fight: " << loser << e.what() << endl;
            }
    }
    removeCharacter(loser->getName());
    return enemy1->getHealth() > 0;
};
