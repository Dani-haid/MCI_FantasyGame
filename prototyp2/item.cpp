#include "item.h"

void Item::initItem(string name, int gold){
    this->name = name;
    this->value = gold;
    this->isValid = true;

};
void Item::initItem(){
    this->isValid = false;
};

string Item::getName(){
    return name;
};

int Item::getValue(){
    return value;
};

bool Item::getIsValid(){
    return isValid;
};

void Item::setName(string name){
    this->name = name;
};

void Item::setValue(int value){
    if(value > 0){
        this->value = value;
    }
};

void Item::setIsValid(bool isValid){
    this->isValid = isValid;
};
