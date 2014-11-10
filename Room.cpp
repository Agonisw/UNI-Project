#include "Enemy.h"
#include "Room.h"
#include "Command.h"


Room::Room(string description) {
	this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
	return "room = " + description + ".\n" + displayEnemies() + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
	// part of the "pair" (<string, Room*>) and return it.
}

 Item* Room::getItemss(int checker){
	
	return &itemsInRoom.at(checker);
	
}

void Room::addItem(Item *inItem) {
	//cout <<endl;
	//cout << "Just added" + inItem->getLongDescription();
	itemsInRoom.push_back(*inItem);
}
void Room::addEnemy(Enemy *inEnemy){
	
	EnemiesInRoom.push_back(*inEnemy);

}
void Room::addLion(Lion *inLion){

	EnemiesInRoom.push_back(*inLion);

}

void Room::setLocked(bool value)
{
	locked = value;
}

bool Room::getLocked()
{
	return locked;
}

string Room::displayItem() {
	string tempString = "items in room = ";
	int sizeItems = (itemsInRoom.size());
	if (itemsInRoom.size() < 1) {
		tempString = "no items in room";
	}
	else if (itemsInRoom.size() > 0) {
		int x = (0);
		for (int n =sizeItems ; n>0; n--) {
			
			tempString = tempString + itemsInRoom[x].getShortDescription() + "  ";
			x++;
		}
	}
	return tempString;
}

string Room::displayEnemies(){
	string tempString = "Enemies in room = ";
	int sizeEnemies = (EnemiesInRoom.size());
	if (EnemiesInRoom.size() < 1) {
		tempString = "no Enemies in room";
	}
	else if (EnemiesInRoom.size() > 0) {
		int x = (0);
		for (int n = sizeEnemies; n > 0; n--) {
			tempString = tempString + EnemiesInRoom[x].getDescription(); +"  ";
			x++;
		}
	}
	return tempString;

}

int Room::numberOfItems() {
	return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)//takes in second word eg: gun is stored as string and compared against the array of items in room's description
{
	int sizeItems = (itemsInRoom.size());
	if (itemsInRoom.size() < 1) {
		return false;
	}
	else if (itemsInRoom.size() > 0) {
		int x = (0);
		for (int n = sizeItems; n > 0; n--) {
			// compare inString with short description
			int tempFlag = inString.compare(itemsInRoom[x].getShortDescription());
			if (tempFlag == 0) {
				
				return x;
			}
			x++;
		}
	}
	return -1;
}

void Room::removeItemFromRoom(int location){

	itemsInRoom.erase(itemsInRoom.begin() + location);

}
string Room::getItems(string word){

	int sizeItems = (itemsInRoom.size());
	if (itemsInRoom.size() < 1) {
		return false;
	}
	else if (itemsInRoom.size() > 0) {
		int x = (0);
		for (int n = sizeItems; n > 0; n--) {
			// compare inString with short description
			int tempFlag = word.compare(itemsInRoom[x].getShortDescription());
			if (tempFlag == 0) {
				itemsInRoom.erase(itemsInRoom.begin() + x);


			}





		}
	}
}
