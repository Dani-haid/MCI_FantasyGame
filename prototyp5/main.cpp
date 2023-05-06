#include <ctime>
#include <cstdlib>
#include "game.h"

using namespace std;


int main() {
    srand(time(nullptr));//Damit random Number immer unterschiedlich ist

    Game game1;
    game1.play();
    return 0;
}