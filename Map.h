#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

#include "Tile.h"

class Map
{
private:
	typedef std::vector<std::vector<Tile>> matrix;
	matrix map;
	int mapLength;
	int mapHeight;

public:
	Map();
	Map(int mapLength, int mapHeight);

	void setTile(int mapx, int mapy, sf::Texture &texture);
	bool loadMap(sf::Texture &texture);
	bool validTilePosition(int x, int y);
	void setTileDefaultPosition(int x, int y, int xLocation, int yLocation);
	void setDefaultTiles(sf::Texture &texture);

	Tile& getTile(int &x, int &y);
	sf::Sprite& getSprite(int &x, int &y);
};

#endif