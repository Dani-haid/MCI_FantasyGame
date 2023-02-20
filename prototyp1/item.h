#ifndef INC_1_SPIELEENTWICKUNG1_ITEM_H
#define INC_1_SPIELEENTWICKUNG1_ITEM_H

struct Item_t{
    char name[256];
    int value;
    bool isValid;
};

void initItem(Item_t* ITEM, char* name, int gold);
void initItem(Item_t* gegenstand);

#endif //INC_1_SPIELEENTWICKUNG1_ITEM_H
