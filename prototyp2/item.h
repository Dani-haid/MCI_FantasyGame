#ifndef INC_1_SPIELEENTWICKUNG1_ITEM_H
#define INC_1_SPIELEENTWICKUNG1_ITEM_H

#include <string>
using namespace std;

class Item{
private:
    string name;
    int value;
    bool isValid;

public:
    void initItem(const string& name, int gold);
    void initItem();

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

#endif //INC_1_SPIELEENTWICKUNG1_ITEM_H
