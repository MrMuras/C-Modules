#include "Zombie.hpp"

int main() {
	Zombie* heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;

	std::string names[] = {"WOJTEK", "CZAREK", "ZDZISIEK", "PAWEL", "Lucek", "MICHAL"};
	srand(time(nullptr));
	randomChump(names[rand() % 6]);

	return 0;
}