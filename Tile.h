//Evan Gordon

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

#include <stdexcept>

class Tile
{
private:
	//need to define what an id is, how it affects information about details of a object ie if its colidable.
	//how does map know these things? do i need to define what they are somewhere?
	sf::Sprite sprite;
	int ID, width, height;
	bool solid;
	//int uv - used for shadows / lighting

public:

	Tile();
	Tile(int ID, bool solid, sf::Texture &texture);
	Tile(int ID, bool solid, int width, int height, sf::Texture &texture);

	void setID(int ID);
	void setSolid(bool solid);
	void setWidth(int width);
	void setHeight(int height);
	void setSpritePosition(int x, int y);

	int getID();
	bool getSolid();
	int getWidth();
	int getHeight();

	sf::Sprite& getSprite();

};

#endif