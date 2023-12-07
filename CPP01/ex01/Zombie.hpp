#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>


class Zombie {
 public:
	Zombie();
	Zombie(std::string name);
	void announce();
	~Zombie();

 private:
	std::string name;
};

Zombie* zombieHorde( int N, std::string name );
#endif 