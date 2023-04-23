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
#include "game.h"

using namespace std;


int main() {

    srand(std::time(nullptr));//Damit random Number immer unterschiedlich ist

    Game game1;
    game1.play();
    return 0;
}