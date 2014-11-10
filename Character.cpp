#include "character.h"
#include <string>
#include <iostream>
using namespace std;

Character::Character(string inDescription, int inHealth, string inWeapon){
	description = inDescription;
	health = inHealth;
	weapon = inWeapon;
	
}

void Character::addHealth(int gain) {
	health += gain;
}

void Character::addDamage(int damage) {
	health -= damage;
}

string Character::getDescription(){
	return description;
}

int Character::getHealth() {
	return health;
}

string Character::getWeapon(){
	return weapon;
}





void Character::setDescription(string description) {
	description = description;
}

void Character::setHealth(int inHealth) {
	health = inHealth;
}

void Character::setWeapon(string Weapon){
	weapon = Weapon;
}
