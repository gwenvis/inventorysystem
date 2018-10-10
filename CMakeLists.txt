cmake_minimum_required(VERSION 3.12)
project(InventorySystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(InventorySystem main.cpp InventorySystem/Inventory.cpp InventorySystem/Inventory.h Models/Item.cpp Models/Item.h InventorySystem/ItemList.cpp InventorySystem/ItemList.h InventorySystem/ItemListLoader.cpp InventorySystem/ItemListLoader.h Helpers/PathHelper.h Models/UseItem.cpp Models/UseItem.h)