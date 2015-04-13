//Evan Gordon

#include "Tile.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

    Tile::Tile()
	{
		ID = 1;
		solid = false;
		width = 32;
		height = 32;
	}
	
	Tile::Tile(int ID, bool solid, sf::Texture &texture)
	{
		this->ID = ID;
		this->solid = solid;
		try
		{			
			sprite = sf::Sprite(texture);
			sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		}
		catch(int e)
		{
         cout<<"Error "<<e<<": "<<"Sprite ID "<<ID<<" does not exist in Tile.\n";
		}
	}

	Tile::Tile(int ID, bool solid, int width, int height, sf::Texture &texture)
	{
		this->ID = ID;
		this->solid = solid;
		this->width = width;
		this->height = height;
		try
		{
			sprite = sf::Sprite(texture);
			sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		}
		catch(int e)
		{
         cout<<"Error "<<e<<": "<<"Sprite ID "<<ID<<" does not exist in Tile.\n";
		}

	}

	void Tile::setID(int ID)
	{
		this->ID = ID;
	}

	void Tile::setSolid(bool solid)
	{
		this->solid = solid;
	}

	void Tile::setWidth(int width)
	{
		this->width = width;
	}

	void Tile::setHeight(int height)
	{
		this->height = height;
	}

	void Tile::setSpritePosition(int x, int y)
	{
		sprite.setPosition(x, y); 
	}

	int Tile::getID()
	{
		return ID;
	}

	bool Tile::getSolid()
	{
		return solid;
	}

	int Tile::getWidth()
	{
		return width;
	}

	int Tile::getHeight()
	{
		return height;
	}

	sf::Sprite& Tile::getSprite()
	{
		return sprite;
	}