#include "sorcerer.h"

void Sorcerer::attack(Character& enemy){
    cout << "attack " << *this << endl;
    //Der Zauberer richtet einen Schaden gemäß folgender Formel an: damage = rand(5, 10) + MagicPower - MagicResistance.
    int x = 5, y = 10;
    int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y
    int damage = rand_num + this->magicPower - enemy.getMagicResistance();
    //cout << "damage: " << "random Number: " << rand_num << " + MagicPower von " << *this << " : " << this->magicPower
    //<< " - MagicResistance von Gegner " << enemy.getName() << " : " << enemy.getMagicResistance()
    //<< " ergibt damage: " <<damage << endl;

    if(damage > 0){
        enemy.setHealth(enemy.getHealth()-damage);
    }else{
        cout << "Angriff von " << *this << " war wirkungslos" << endl;
    }

    cout << *this << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte!" << enemy.getName() << " besitzt jetzt noch " << enemy.getHealth() << " Lebenspunkte."  << endl;
};

ostream& operator<<(ostream& out, Sorcerer& s){
    out << "Sorcerer " << s.getName();
    return out;
};
