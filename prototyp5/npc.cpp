#include "npc.h"

shared_ptr<Item> Npc::retrieveRandomLoot(){
    //Gegenstand entfernen und zurückgeben
    if(inventory.size() > 0){
        int rand_num = rand() % inventory.size(); //zufälliger Slot;
        auto it = inventory.begin();
        for (int i = 0; i < rand_num; i++) {
            it++;
        }
        return it->second;
    }
    throw NoItemFoundException(" Kein Item im Inventar des Characters gefunden.");
};
