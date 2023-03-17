#ifndef PROTOTYP3_ITEM_H
#define PROTOTYP3_ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item{
private:
    string name;
    int value;
    bool isValid;

public:
    //default constructor
    Item():name(""), value(0), isValid(false){};

    //constructor
    Item(const string& name, int value):name(name), value(value), isValid(true){
        cout << "Item " << this->name << " erstellt" << endl;
    }

    //destructor
    ~Item(){};

    //void initItem(const string& name, int gold);
    //void initItem();

    //getter:
    bool getIsValid(){
        return isValid;
    };
    string getName(){
        return name;
    };
    int getValue(){
        return value;
    };


    //setter:
    void setIsValid(bool isValid){
        this->isValid = isValid;
    };
    void setName(string& name){
        this->name = name;
    };
    void setValue(int value){
        this->value = value;
    };


};


#endif //PROTOTYP3_ITEM_H
