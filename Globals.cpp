#include "globals.h"
#include <iostream>

Globals::Globals()
{
	textures[0].fileName = "overWorld.png";
	cameraPosition.x = 0;
	cameraPosition.y = 0;	
}

Globals::Globals(int mapx,int mapy, int cameraX, int cameraY)
{
	textures[0].fileName = "overWorld.png";
	gameMap.setDefaultTiles(textures[0].texture);
	cameraPosition.x = cameraX;
	cameraPosition.y = cameraY;
}

void Globals::runGame()
{
	//window and view setup
	sf::RenderWindow window(sf::VideoMode(1280, 640), "Kill It With Fire!");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	sf::View view(sf::FloatRect(0, 0, 1280, 640));
	window.setView(view);
	view.setCenter(0, 0);

	//tiles setup - map loading
	if(!textures[0].texture.loadFromFile(textures[0].fileName))
			{
			throw(42);
			}
	gameMap = Map(100, 100);
	gameMap.setDefaultTiles(textures[0].texture);
	for(int i = 0; i < 40; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(gameMap.validTilePosition(i, j))
			{
				gameMap.setTileDefaultPosition(i, j, i*32, j*32);
			}
		}
	}

	//game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
        }


		//check for movement keys pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				//move up
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			//move down
			view.move(360.0f, 0.0f);
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
			{
				//move left
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//right
			view.move(0.0, 1.0);
		}
        window.clear();
        drawGameMap(window);
        window.display();
    }
}

void Globals::drawGameMap(sf::RenderWindow& window)
{
	//later add function for drawing map with current offset.

	//draw map third
	for(int i = 0; i < 40; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(gameMap.validTilePosition(i, j))
			{
				window.draw(gameMap.getSprite(i, j));
			}
		}
	}
}

