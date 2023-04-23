#include "game.h"
#include "character.h"
#include "hero.h"

void Game::play(){
    cout << "jetzt wird gespielt " << endl;

    characters.insert(make_pair("annina", new Hero("Annina", 300, 50, 50, 15)));

    //andere Methode: pair und insert getrennt machen:
    /*pair<string, Character*> myPair = make_pair("TestHero", new Hero("TestHero", 343, 234, 234 , 3423));
    characters.insert(myPair);*/

    tempMapOutput();

};

/*void Game::add(Character* character){
    characters[character->getName()] = character;

    for( auto it = characters.begin(); it != characters.end() ; it ++) {
        cout << " Key : " << it->first
                <<" , Value : " << it->second
                << endl ;
    }
}*/

void Game::tempMapOutput() {
    for (auto it = characters.begin(); it != characters.end(); it++) {
        cout << " Key : " << it->first
             << " , Value : " << it->second
             << endl;
    }
}
