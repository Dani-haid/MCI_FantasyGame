#ifndef PROTOTYP4_ITEM_H
#define PROTOTYP4_ITEM_H

#include <string>
#include <iostream>
#include "exceptions.h"
using namespace std;

class Item{
private:
    string name;
    int value;

public:
    //constructor
    Item(const string& name, int value);

    ~Item(){
        cout << "Item " << this->getName() << " wurde zerstört." << endl;
    }

    //getter:
    string getName()const{
        return name;
    };
    int getValue()const{
        return value;
    };


    //setter:
    void setName(string& name){
        if(name.size() > 0){
            this->name = name;
        }else{
            throw WrongValueException("setName Item: ungültiger Wert für Name!");
        }
    };

    void setValue(int value){
        if (value >= 0){
            this->value = value;
        }else{
            throw WrongValueException("setValue Item: negativer Wert ist ungültig!");
        }
    };
};

ostream& operator<<(ostream& out, const Item* h);
ostream& operator<<(ostream& out, const Item& h);
ostream& operator<<(ostream& out, const shared_ptr<Item> h);


#endif //PROTOTYP4_ITEM_H
