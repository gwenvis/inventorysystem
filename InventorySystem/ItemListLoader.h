//
// Created by Antoine Botteler on 08/10/2018.
//

#ifndef INVENTORYSYSTEM_ITEMLISTLOADER_H
#define INVENTORYSYSTEM_ITEMLISTLOADER_H


#include <string>
#include "../Models/Item.h"

class ItemListLoader {
public:
    // loads item from the path and fills them in the item vector.
    static void loadItems(std::string, std::vector<Item*>*);
    static void setID(Item *);
};


#endif //INVENTORYSYSTEM_ITEMLISTLOADER_H
