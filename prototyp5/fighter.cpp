#include "fighter.h"

//constructor
Fighter::Fighter(Game* manager, const string& name, int health, int gold, int armor, int magicResistance, int strength)
        : Npc(manager, name, health, gold, armor, magicResistance), strength(strength){
    if(strength < 0){
        throw WrongValueException("Constructor: Negative Werte sind ungültig!");
    }
    cout << *this << " erstellt" << endl;
};

 void Fighter::attack(Character& enemy){
     int x = 5, y = 10;
     int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y
     int damage = rand_num + this->strength - enemy.getArmor();

     if(damage > 0){
         enemy.setHealth(enemy.getHealth()-damage);
         cout << *this << " trifft " << enemy << " für " << damage << " Lebenspunkte!"
              << enemy << " besitzt jetzt noch " << enemy.getHealth() << " Lebenspunkte."  << endl;
     }else{
         cout << "Angriff von " << *this << " war wirkungslos. "
         << enemy << " besitzt weiterhin " << enemy.getHealth() << " Lebenspunkte." << endl;
     }


};

ostream& operator<<(ostream& out, Fighter& f){
    out << "Fighter " << f.getName();
    return out;
}
