#include "fighter.h"

 void Fighter::attack(Character& enemy){
     cout << "attack Fighter" << endl;
     //Der Kämpfer richtet einen Schaden gemäß folgender Formel an: damage = rand(5, 10) + Strength - Armor.
     int x = 5, y = 10;
     int rand_num = rand()%((y+1)-x) + x; //Zufallszahl zwischen x und y
     int damage = rand_num + this->strength - enemy.getArmor();
     cout << "damage: " << damage << endl;
     cout << "damage: " << "random Number: " << rand_num << " + strength von " << this->getName() << " : " << this->strength << " - armor von Gegner " << enemy.getName() << " : " << enemy.getArmor() << " ergibt damage: " <<damage << endl;

     if(damage > 0){
         enemy.setHealth(enemy.getHealth()-damage);
     }else{
         cout << "Angriff von " << this->getName() << " war wirkungslos" << endl;
     }

     cout << this->name << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte!" << enemy.getName() << " besitzt jetzt noch " << enemy.getHealth() << " Lebenspunkte."  << endl;

};
