#include "Zombie.hpp"

int main(){

	srand(time(nullptr));
	int zombieNumber = rand() % 10;
	Zombie* horde = zombieHorde(zombieNumber, "Zombie Wojtek" );
	for(int i = 0; i < zombieNumber; i++)
		horde[i].announce();
	
	delete[] horde;
}