#include "inventory.h"
#include "zorkUL.h"
#include "room.h"

Inventory::Inventory()
{
}

void Inventory::addItem(Item *inItem)//doesnt return anything just adds item to inventory takes in item and puts it in inventory
{
	inventory.push_back(*inItem);
}



void Inventory::deleteItem(int i)
{
	inventory.erase(inventory.begin() + i);
}

bool Inventory::hasItem(int i){
	if (inventory.size() > i){
		return true;
	}
	return false;
}



void Inventory::displayItems() {
	string tempString = "items in inventory = ";
	int sizeItems = (inventory.size());
	if (inventory.size() < 1) {
		tempString = "no items in inventory";
		
	}
	else if (inventory.size() > 0) {
		int x = (0);
		for (int n = 0; n < sizeItems; n++) {
			tempString = tempString + inventory[x].getShortDescription() + "  ";
			x++;
			
		}
	}
	cout << tempString << endl;
}




int Inventory::getSize(){
	return inventory.size();
}


