//
// Created by Antoine Botteler on 03/10/2018.
//

#include <iostream>
#include "Inventory.h"

Inventory::~Inventory() {
    for (auto &it : this->current) {
        delete it;
    }
}

Item *Inventory::findItem(unsigned int id) {
    for (auto &it : this->current) {
        if(it->id == id) return it;
    }

    return nullptr;
}

void Inventory::removeFromArray(Item *item)
{
    for(auto it = current.begin(); it != current.end(); ++it) {
        if((*it)->id == item->id)
        {
            this->current.erase(it);
            delete item;
            break;
        }
    }
}

bool Inventory::removeItem(const int id, const int stackCount) {
    // find the item.
    Item *fi = findItem(id);

    // item has not been found, return.
    if(fi == nullptr) return false;

    /// if the item has been found, substract the stack count from the current stack.
    fi->stack -= stackCount;

    /// when it's below 0, remove the item from the array.
    if(fi->stack <= 0) removeFromArray(fi);

    return true;
}

void Inventory::addItem(Item *item, const int stackCount) {
    //find the item
    Item *fi = findItem(item->id);

    if(fi == nullptr)
    {
        /// if the item has not been found in the inventory,
        /// the memory of the supplied object will be copied.
        Item *newItem = item->clone();
        std::cout << stackCount << std::endl;
        newItem->stack = stackCount;
        current.push_back(newItem);
    }
    else
    {
        /// if the item has been found,
        /// just increase the stack count.
        fi->stack += stackCount;
    }
}

std::vector<Item *> *Inventory::getInventory() {
    return &this->current;
}

