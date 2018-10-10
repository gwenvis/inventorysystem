//
// Created by Antoine Botteler on 08/10/2018.
//

#ifndef INVENTORYSYSTEM_ITEMLIST_H
#define INVENTORYSYSTEM_ITEMLIST_H


#include <vector>
#include "../Models/Item.h"

class ItemList {
public:
    static std::vector<Item*> itemList;
    static std::vector<Item*> findItems(std::string);
    static Item *getItemByID(int);

    static void init();
private:

};


#endif //INVENTORYSYSTEM_ITEMLIST_H
