//
// Created by Antoine Botteler on 03/10/2018.
//

#ifndef INVENTORYSYSTEM_INVENTORY_H
#define INVENTORYSYSTEM_INVENTORY_H

#include <vector>
#include "../Models/Item.h"

class Inventory {
public:
    Inventory() = default;
    ~Inventory();

    void addItem(Item *, int = 1);
    bool removeItem(int, int = 1);
    Item *findItem(unsigned int);
    std::vector<Item *> *getInventory();

private:
    std::vector<Item *> current;
    void removeFromArray(Item *);
};


#endif //INVENTORYSYSTEM_INVENTORY_H
