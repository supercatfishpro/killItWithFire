#include "Map.h"
#include <string>

Map::Map()
{   
	mapLength = 50;
	mapHeight = 50;
	map.resize(50);

	for(int i = 0; i < 50; i++)
	{
		map[i].resize(50);
	}
}


//x and y are the length and width of map
Map::Map(int mapLength, int mapHeight)
{
	this->mapLength = mapLength;
	this->mapHeight = mapHeight;
	map.resize(mapLength);

	for(int i = 0; i < mapLength; i++)
	{
		map[i].resize(mapHeight);
	}


}

//this needs revisions, how and what information about a tile will this funtion know?
void Map::setTile(int mapx, int mapy, sf::Texture &texture)
{
	map[mapx][mapy] = Tile(1, false, texture);
}

//used to change the position of a tile based on the given values
void Map::setTileDefaultPosition(int x, int y, int xLocation, int yLocation)
{
	map[x][y].setSpritePosition(xLocation, yLocation);
}

void Map::setDefaultTiles(sf::Texture &texture)
{
	for(int i = 0; i < mapLength; i++)
	{
		for(int j = 0; j < mapHeight; j++)
		{
			map[i][j] = Tile(1, false, texture);
		}

	}
}

//check if given tile position is valid
//used for current drawing function
bool Map::validTilePosition(int x, int y)
{
	if(x >= 0 && y >= 0)
	{
		if(x <= mapLength && y <= mapHeight)
		{
			return true;
		}
	}
	return false;
}

//add image to all tiles function
bool Map::loadMap(sf::Texture &texture)
{
	for(int i = 0; i < mapHeight; i++)
	{
		for(int j = 0; j < mapLength; j++)
		{
			setTile(i, j, texture);
		}
	}
	return true;
}

Tile& Map::getTile(int &x, int &y)
{
	return map[x][y];//maybe the problem is here
}

sf::Sprite& Map::getSprite(int &x, int &y)
{
	return map[x][y].getSprite();//problem more than likely here
}