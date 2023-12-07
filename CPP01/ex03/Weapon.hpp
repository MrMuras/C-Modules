#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(const std::string&);
		const std::string& getType() const;
		void setType(const std::string&);
		
	private:
		std::string _type;
		
};

#endif