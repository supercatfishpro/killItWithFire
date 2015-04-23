//Evan Gordon

#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>


#include "Map.h"
#include "Button.h"
#include "Character.h"

//remove late and replace with menu object
#include "UI.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

struct TextureArray
{
	std::string fileName;
	sf::Texture texture;
};

class Globals
{
private:	
	static sf::Vector2i cameraPosition;
	static sf::RenderWindow window;
	static sf::Event event;
	static sf::View view;
	static sf::View userInterface;
	static sf::Font gameFont;

	TextureArray textures[5];
	Map gameMap;
	 //temp fix - 1 is for game 2 is for mapMaker
	int gameMode;

	Character player;
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

	void mainMenu();
	void initializeGame();
	void drawGameMap();//write this function
	void runGame();
	void runMapMaker();

	sf::Texture getTexture(int textureNumb);
		
};

#endif 

