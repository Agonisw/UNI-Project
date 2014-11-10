#include <iostream>
#include "character.h"
#include "inventory.h"
#include "ZorkUL.h"
#include "room.h"



using namespace std;


Character *CharPointer = NULL;
	Inventory *InventPointer = NULL;

int main(int argc, char argv[]) {
	ZorkUL temp;
	temp.play();
	
	
	return 0;
	
}

ZorkUL::ZorkUL() {
	createRooms();
	CharPointer = new Character("MC", 100, "Fists of Fury");
	InventPointer = new Inventory();
	
}






void ZorkUL::createRooms()  {
	Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n;
	
	a = new Room("Beach camp");
	a->addItem(new Item("gun",2,2,true));
	a->addItem(new Item("bow", 2, 2, true));
	a->addItem(new Item("stick", 2, 2, true));
	a->addLion(new Lion("alligator", 10));
	b = new Room("left beach");
	b->addEnemy(new Enemy("lion",25,"claws"));
	c = new Room("right beach");
	c->addEnemy(new Enemy("maniac",40,"gun"));
	d = new Room("jungle");
	e = new Room("left jungle");
	f = new Room("right jungle");
	g = new Room("left cave");
	h = new Room("cave");
	i = new Room("cave with opening to sky");
	j = new Room("jungle dead end");
	k = new Room("weird place");
	l = new Room("ruin entrance");
	m = new Room("underground ruin");
	n = new Room("hidden room");

	//             (N, E, S, W)
	a->setExits(d, c, NULL, b);
	b->setExits(NULL, a, NULL, NULL);
	c->setExits(NULL, NULL, NULL, a);
	d->setExits(h, f, a, e);
	e->setExits(j, d, NULL, NULL);
	f->setExits(l, NULL, NULL, d);
	g->setExits(NULL, h, NULL, NULL);
	h->setExits(NULL, i, d, g);
	i->setExits(NULL, NULL, NULL, h);
	j->setExits(k, NULL, e, NULL);
	k->setExits(NULL, NULL, j, NULL);
	l->setExits(NULL, m, f, NULL);
	m->setExits(NULL, n, NULL, l);
	n->setExits(NULL, NULL, NULL, m);

	currentRoom = a;
}

/**
*  Main play routine.  Loops until end of play.
*/
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();

		//cout << command->getCommandWord() << endl;

		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "You wake up, your head pounding, to the sound of the ocean waves splashing" << endl;
	cout << "You look around and see an island one one side, the never ending ocean on the other" << endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
* Given a command, process (that is: execute) the command.
* If this command ends the ZorkUL game, true is returned, otherwise false is
* returned.
*/
bool ZorkUL::processCommand(Command command) {

	//cout << "'" << command->getCommandWord() << "'";

	if (command.isUnknown()) {
		cout << "invalid input" << endl;
		return false;
	}

	string commandWord = command.getCommandWord();

	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
	{
		cout << "[g] --- [h] --- [i]        " << endl;
		cout << "         |                 " << endl;
		cout << "         |                 " << endl;
		cout << "[k]      |                   " << endl;
		cout << " |       |                   " << endl;
		cout << " |       |         " << endl;
		cout << "[j]      |      [l] --- [m] --- [n]" << endl;
		cout << " |       |       |  " << endl;
		cout << " |       |       | " << endl;
		cout << "[e] --- [d] --- [f]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[b] --- [a] --- [c]" << endl;
	}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

	else if (commandWord.compare("take") == 0)
	{
		if (!command.hasSecondWord()) {
			cout << "incomplete input" << endl;
		}
		else
			if (command.hasSecondWord()) {
			cout << "you're trying to take " + command.getSecondWord() << endl;
			int location = currentRoom->isItemInRoom(command.getSecondWord());
			if (location < 0)
				cout << "item is not in room" << endl;
			else
				cout << "item is in room" << endl;
			cout << "index number " << +location << endl;
			InventPointer->addItem(currentRoom->getItemss(location));
			currentRoom->removeItemFromRoom(location);
			cout << endl;
			cout << currentRoom->longDescription() << endl;
			}
	}

	else if (commandWord.compare("put") == 0)
	{

	}
	/*
	{
	if (!command.hasSecondWord()) {
	cout << "incomplete input"<< endl;
	}
	else
	if (command.hasSecondWord()) {
	cout << "you're adding " + command.getSecondWord() << endl;
	itemsInRoom.push_Back;
	}
	}
	*/
	else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input" << endl;
		else
			return true; /**signal to quit*/
	}
	else if (commandWord.compare("equip") == 0){
		if (!command.hasSecondWord()) {
			cout << "incomplete input" << endl;
		}
		else
			if (command.hasSecondWord()) {
			cout << "you're adding " << endl;
			//equip second word if it is equipable
			}
	}
	else if (commandWord.compare("check") == 0){
		cout << "You check what weapon you have equipped\n " << endl;
		

	}
	else if (commandWord.compare("status") == 0){
		cout << CharPointer->getDescription() << endl;
		cout << CharPointer->getHealth() << endl;
		cout << CharPointer->getWeapon() << endl;
	}
	else if (commandWord.compare("inventory") == 0){
		
		 InventPointer->displayItems();
		 
	}
	
	return false;
  
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input" << endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input" << endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
