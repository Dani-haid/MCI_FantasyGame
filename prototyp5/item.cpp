#include "item.h"
#include <iostream>

using namespace std;

//constructor
Item::Item(const string& name, int value):name(name), value(value){
    //cout << "Item " << this->name << " erstellt" << endl;
}

ostream& operator<<(ostream& out, const Item* h){
    out << "Gegenstand " << h->getName();
    return out;
};
ostream& operator<<(ostream& out, const Item& h){
    out << "Gegenstand " << h.getName();
    return out;
};

ostream& operator<<(ostream& out, const shared_ptr<Item> h){
    out << "Gegenstand " << h->getName();
    return out;
}
