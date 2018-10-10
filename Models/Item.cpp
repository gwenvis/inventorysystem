//
// Created by Antoine Botteler on 03/10/2018.
//

#include "Item.h"

Item::Item() {

}

bool Item::Use() {
    if(uses > 0) uses -= 1;
    internal_use();
}

bool Item::Equip() {
    internal_equip();
}
