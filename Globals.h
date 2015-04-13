//Evan Gordon

#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <string>

#include "Map.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <stdexcept>

struct Point
{
int x;
int y;
};

struct TextureArray
{
	std::string fileName;
	sf::Texture texture;
};

class Globals
{
private:	
	TextureArray textures[1];
	Map gameMap;
	Point cameraPosition;

	//ai for enemies
	//assume this is a survival game,
	//if it is then ai's arent particularly targeting you over another ai
	//lets assume they have multiple methods of killing an enemy, for example
	//fist, foot, or staff
	//if ai gets kill with staff then that skill levels up and that specific ai becomes better,
	//this state is also possibly saved if the player is killed
	//what this would cause is a more dynamic world that seemed more alive
	//this could also initialize the neural network programming technique i want to implement
public:
	Globals();
	Globals(int mapx, int mapy, int cameraX, int cameraY);

	void runGame();
	void drawGameMap(sf::RenderWindow& window);//write this function
		
};

#endif 