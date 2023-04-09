#include "sorcerer.h"
#include <iostream>

void Sorcerer::attack(Character& enemy){
    int x = 5, y = 10;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y
    int damage = rand_num + this->magicPower - enemy.getMagicResistance();

    if(damage > 0){
        enemy.setHealth(enemy.getHealth()-damage);
        cout << *this << " trifft " << enemy << " für " << damage << " Lebenspunkte! "
             << enemy << " besitzt jetzt noch " << enemy.getHealth() << " Lebenspunkte."  << endl;
    }else{
        cout << "Angriff von " << *this << " war wirkungslos. "
        << enemy << " besitzt weiterhin " << enemy.getHealth() << " Lebenspunkte."  << endl;
    }
};

ostream& operator<<(ostream& out, Sorcerer& s){
    out << "Sorcerer " << s.getName();
    return out;
};
