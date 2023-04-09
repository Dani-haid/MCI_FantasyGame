#include "item.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const Item* h){
    out << "Gegenstand " << h->getName();
    return out;
};
ostream& operator<<(ostream& out, const Item& h){
    out << "Gegenstand " << h.getName();
    return out;
};
