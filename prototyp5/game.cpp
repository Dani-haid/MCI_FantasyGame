#include "game.h"
#include "character.h"

void Game::play(){
    //tbd
};

void Game::add(Character* character){
    characters[character->getName()] = character;
    for( auto it = characters.begin(); it != characters.end() ; it ++) {
        cout << " Key : " << it->first
                <<" , Value : " << it->second
                << endl ;
    }
};
