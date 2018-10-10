//
// Created by Antoine Botteler on 08/10/2018.
//

#include "ItemListLoader.h"
#include "../Helpers/PathHelper.h"
#include "../Models/UseItem.h"

/// I should actually write my own parser for this so it loads a file and parses the items in there, then adds them to the list.
/// But because that's not the assignment I got, I will just hard code the possible items.
/// frig off!!!!!
void ItemListLoader::loadItems(std::string path, std::vector<Item *> *itemList)
{
    auto *item = new UseItem();
    item->name = "Cool Item";
    item->description = "This might even be the coolest item you've ever seen.";
    item->uses = -1;
    setID(item);

    auto *item2 = new UseItem();
    item2->name = "Less Cool Item";
    item2->description = "This Item is a Little Bit Less Cool Than The Other One.";
    setID(item);

    itemList->push_back(item);
    itemList->push_back(item2);
}

unsigned int lastID = 0;
void ItemListLoader::setID(Item *item)
{
    item->id = lastID++;
}