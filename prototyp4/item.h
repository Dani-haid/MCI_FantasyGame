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
    //bool isValid;

public:
    //default constructor
    Item():name(""), value(0){};
    //Item():name(""), value(0), isValid(false){};

    //constructor
    Item(const string& name, int value):name(name), value(value){
        //Item(const string& name, int value):name(name), value(value), isValid(true){
        //cout << "Item " << this->name << " erstellt" << endl;
    }

    //destructor
    ~Item(){
        //cout << "destructor Item " << this->name << endl;
    };

    //getter:
    /*bool getIsValid()const{
        return isValid;
    };*/
    string getName()const{
        return name;
    };
    int getValue()const{
        return value;
    };


    //setter:
    /*void setIsValid(bool isValid){
        this->isValid = isValid;
    };*/
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


#endif //PROTOTYP4_ITEM_H
