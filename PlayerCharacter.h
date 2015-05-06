//Evan Gordon

#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "Character.h"
#include "CooldownBar.h"

#include <SFML/Graphics.hpp>

//child class of Character, is like bace character class but handles ui elements such as health and cooldown bar
class PlayerCharacter: public Character
{
private:
	CooldownBar weaponCooldownBar;
public:
	PlayerCharacter();
	PlayerCharacter(sf::Texture& texture);

	int attack(sf::Time& gameTime);
	void draw(sf::RenderWindow& window, sf::Clock& gameClock);
};

#endif