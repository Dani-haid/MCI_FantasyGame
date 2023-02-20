#include <cstring>
#include "item.h"

void initItem(Item_t* ITEM, char* name, int gold){
    strcpy(ITEM->name, name);
    ITEM->value = gold;
    ITEM->isValid = true;

};
void initItem(Item_t* gegenstand){
    gegenstand->isValid = false;
};
