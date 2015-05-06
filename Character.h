
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

#include <stdexcept>

//make this a parent class, and have a player character class that also includes the cooldown bar?
class Character
{
private:

	sf::Sprite character;
	int animationNumber, orientation; //orientation is currently 1-4 int representing curr direction
	sf::Vector2f location;
	sf::IntRect drawRect;

public:

	Character();
	Character(sf::Texture& texture);

	void animate(); 
	virtual int attack(sf::Clock& gameClock);//returns an int to declare to globals what type of particle is desired?

	void setOrientation(int orientation);
	void setLocation(int x, int y);
	void setLocation(sf::Vector2f);
	void setSpritePostion(sf::Vector2f);

	int getOrientation();
	sf::Vector2f getLocation();
	sf::Sprite& getSprite();


};
#endif