//
// Created by Antoine Botteler on 08/10/2018.
//

#include "ItemList.h"
#include "ItemListLoader.h"
#include <algorithm>
#include <string>
#include <iostream>

std::vector<Item*> ItemList::itemList;

std::vector<Item*> ItemList::findItems(std::string searchQuery) {
    if(searchQuery.empty()) return itemList;

    std::vector<Item*> possibilities;
    std::transform(searchQuery.begin(), searchQuery.end(), searchQuery.begin(), ::tolower);
    std::cout << searchQuery << std::endl;

    for(auto it = itemList.begin(); it != itemList.end(); ++it) {
        std::string c;
        c.append((*it)->name);
        std::transform(c.begin(), c.end(), c.begin(), ::tolower);

        if(c.find(searchQuery) != std::string::npos) {
            // found, add to possibilities
            possibilities.push_back(*it);
        }
    }

    return possibilities;
}

void ItemList::init() {
    ItemListLoader::loadItems("", &itemList);
}

Item *ItemList::getItemByID(const int id)
{
    for(auto &it : ItemList::itemList)
    {
        if(it->id == id) return it;
    }

    throw -1;
}
