#ifndef INC_1_SPIELEENTWICKUNG1_ITEM_H
#define INC_1_SPIELEENTWICKUNG1_ITEM_H

using namespace std;
#include <string>

class Item{
private:
    string name;
    int value;
    bool isValid;

public:
    void initItem(string name, int gold);
    void initItem();

    //getter:
    string getName();
    int getValue();
    bool getIsValid();

    //setter:
    void setName(string name);
    void setValue(int value);
    void setIsValid(bool isValid);

};

#endif //INC_1_SPIELEENTWICKUNG1_ITEM_H
