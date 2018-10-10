//
// Created by Antoine Botteler on 03/10/2018.
//

#ifndef INVENTORYSYSTEM_ITEM_H
#define INVENTORYSYSTEM_ITEM_H

#include <string>

class Item {
public:
    Item();
    virtual Item *clone() { return (new Item(*this)); }

    unsigned int id;
    std::string name;
    std::string description;
    int maxStack;
    int stack;
    int uses = 1;
    bool Use();
    bool Equip();

private:
    virtual bool internal_use() { return false; };
    virtual bool internal_equip() { return false; }
};


#endif //INVENTORYSYSTEM_ITEM_H
