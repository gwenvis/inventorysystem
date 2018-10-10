//
// Created by Antoine Botteler on 10/10/2018.
//

#ifndef INVENTORYSYSTEM_USEITEM_H
#define INVENTORYSYSTEM_USEITEM_H


#include "Item.h"
#include <iostream>

class UseItem : public Item {
public:
    UseItem *clone() override { return (new UseItem(*this)); }

    bool internal_use() override {
        std::cout << "You used " << this->name << "." << std::endl;
    }
};


#endif //INVENTORYSYSTEM_USEITEM_H
