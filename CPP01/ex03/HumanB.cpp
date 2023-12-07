#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name):
	_name(name),
	_weapon(nullptr) 
{}

void HumanB::setWeapon(Weapon& newWeapon) {
	_weapon = &newWeapon;
}

void HumanB::attack() const {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " is unarmed!" << std::endl;
}