#include <iostream>
#include <map>
#include "InventorySystem/ItemList.h"
#include "InventorySystem/Inventory.h"

enum cmd {
    cmd_unknown,
    cmd_help,
    cmd_give,
    cmd_use,
    cmd_drop,
    cmd_find,
    cmd_inventory,
    cmd_info,
    cmd_exit
};

static const std::map<std::string, cmd> commandValues = {
        {"help", cmd_help},
        {"give", cmd_give},
        {"use", cmd_use},
        {"drop", cmd_drop},
        {"exit", cmd_exit},
        {"inv", cmd_inventory},
        {"info", cmd_info},
        {"find", cmd_find}
};

Inventory *inventory;

cmd getCmd(const std::string *command) {
    if(commandValues.find(*command) == commandValues.end()) return cmd_unknown;

    return commandValues.at(*command);
}

void findItems(const std::string *itemName)
{
    auto
        i = ItemList::findItems(*itemName);


    for(auto &it : i)
    {
        std::cout << it->id << "\t\t" << it->name << std::endl;
    }
}

void printInventory()
{
    auto inv = inventory->getInventory();

    for(auto &it : *inv)
    {
        std::cout << it->id << "\t\t" << it->name << std::endl;
    }
}

int processCommand(const std::string *cmd, const std::string *args)
{
    int id;
    Item* item;

    switch(getCmd(cmd))
    {
        case cmd_exit:
            return 1;
        case cmd_unknown:
            std::cout << *cmd << " is an unknown command. Write \"help\" for a list of possible commands." << std::endl;
            break;
        case cmd_give:
            //parse id
            id = std::stoi(*args);
            item = ItemList::getItemByID(id);
            inventory->addItem(item, 1);
            std::cout << "Item has been added." << std::endl;
            break;
        case cmd_find:
            findItems(args);
            break;
        case cmd_help:
            std::cout << "possible commands:" << std::endl;
            std::cout << "find {item name} \t\t: returns a list of item names with their ID. No args returns all items." << std::endl;
            std::cout << "give {item id} \t\t: gives you (1) of item." << std::endl;
            std::cout << "use {item id} \t\t: uses the item if you have it in your inventory." << std::endl;
            std::cout << "inv \t\t: get your inventory." << std::endl;
            std::cout << "drop {item id} \t\t: drop (1) of item if you have it in your inventory." << std::endl;
            std::cout << "info {item id} \t\t: get more info of this particular item." << std::endl;
            std::cout << "exit \t\t: exits the program." << std::endl;
            break;
        case cmd_use:
            id  = std::stoi(*args);
            item = inventory->findItem(id);

            if(item != nullptr) {
                item->Use();

                std::cout << item->uses << std::endl;

                /// If item uses is 0 ( it cannot go lower unless uses are unlimited (-1) )
                /// the item will have to be deleted from the inventory. Or (1) stack will have to be deleted.
                /// The inventory should probably have a `USE` function, which deletes it itself. But Eh.
                if(item->uses == 0)
                {
                    std::cout << item->name << " has been depleted.";
                    inventory->removeItem(item->id, 1);
                }
            }
            break;
        case cmd_drop:
            id = std::stoi(*args);
            inventory->removeItem(item->id);
            break;
        case cmd_inventory:
            printInventory();
            break;
        case cmd_info:
            if(args->empty()) {
                std::cout << "Make sure to enter (something) a correct id!\nAs I don't check if it even is a number before parsing it, it might crash. That's on you." << std::endl;
                break;
            }

            /// parse id
            id = std::stoi(*args);
            item = inventory->findItem(id);
            if(item == nullptr)
            {
                std::cout << "Item has not been found in your inventory! Add it first." << std::endl;
                break;
            }

            std::cout << item->name << "\t\tCurrent stack: " << item->stack << std::endl;
            std::cout << "id: " << item->id << std::endl << item->description << std::endl;

            break;
    }

    return 0;
}

int main() {

    ItemList::init();
    inventory = new Inventory();

    std::cout << "write \"help\" for the command list." << std::endl;

    while(true)
    {
        std::string cmd;
        std::getline(std::cin, cmd);

        // lower it
        std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        // get the arguments
        size_t f;
        std::string args;

        f = cmd.find_first_of(' ');
        if(f == std::string::npos) {
            f = cmd.length();
            args = "";
        }
        else {
            args = cmd.substr(f+1);
        }

        cmd = cmd.substr(0, f);

        if(processCommand(&cmd, &args) != 0)
            break;
    }



    return 0;
}