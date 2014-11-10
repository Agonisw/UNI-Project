#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;

Enemy::Enemy(string inDescription, int inHealth, string inWeapon){
	Edescription = inDescription;
	Ehealth = inHealth;
	Eweapon = inWeapon;

}

void Enemy::addHealth(int gain) {
	Ehealth += gain;
}

void Enemy::addDamage(int damage) {
	Ehealth -= damage;
}

string Enemy::getDescription(){
	return Edescription;
}

int Enemy::getHealth() {
	return Ehealth;
}

string Enemy::getWeapon(){
	return Eweapon;
}

void Enemy::setDescription(string description) {
	Edescription = description;
}

void Enemy::setHealth(int inHealth) {
	Ehealth = inHealth;
}

void Enemy::setWeapon(string Weapon){
	Eweapon = Weapon;
}


