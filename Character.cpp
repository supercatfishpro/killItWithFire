
#include "Character.h"
#include <iostream>

	Character::Character()
	{
	animationNumber  = 0;
	orientation = 0;
	drawRect = sf::IntRect(0, 1, 32, 64);
	}

	Character::Character(sf::Texture& texture)
	{
		animationNumber  = 0;
		orientation = 0;
		drawRect = sf::IntRect(0, 0, 32, 64);
	try
		{			
			character = sf::Sprite(texture);
			character.setTextureRect(drawRect);
			character.setOrigin(16, 48);
		}
		catch(int e)
		{
         std::cout<<"Error "<<e<<": "<<"Character does not exist in Tile.\n";
		}

	}

	void Character::animate() 
	{
	//used to determine the current animation element
	//if movement is still being pushed  then current animation++ %animationNumber

	}
	int Character::attack()
	{
		//later change animation

		//add effect
	return 1;
	}

	void Character::setOrientation(int orientation)
	{
	this->orientation = orientation;
	if(orientation > 1)
	{
		if(orientation ==2)
		{
		drawRect.top = orientation * 64 + 5;
		}
		else
		{
		drawRect.top = orientation * 64 + 10;
		}
	}
	else
	{
	drawRect.top = orientation * 64;
	}
	character.setTextureRect(drawRect);
	}

	void Character::setLocation(int x, int y)
	{
		location.x = x;
		location.y = y;
	}

	void Character::setLocation(sf::Vector2f location)
	{
	this->location = location;
	}

	//for location on screen
	void Character::setSpritePostion(sf::Vector2f drawLocation)
	{
		character.setPosition(drawLocation); 
	}


	int Character::getOrientation()
	{
	return orientation;
	}
	sf::Vector2f Character::getLocation()
	{
		return location;
	}

	sf::Sprite Character::getSprite()
	{
		return this->character;
	}