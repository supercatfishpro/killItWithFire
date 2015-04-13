//Evan Gordon

#include "globals.h"
#include <iostream>

Globals::Globals()
{
	textures[0].fileName = "overWorld.png";
	textures[1].fileName = "menuButton.png";
	textures[2].fileName = "menuButtonPressed.png";
	cameraPosition.x = 0;
	cameraPosition.y = 0;	
}

Globals::Globals(int mapx,int mapy, int cameraX, int cameraY)
{
	textures[0].fileName = "overWorld.png";
	textures[1].fileName = "menuButton.png";
	textures[2].fileName = "menuButtonPressed.png";
	gameMap.setDefaultTiles(textures[0].texture);

	cameraPosition.x = cameraX;
	cameraPosition.y = cameraY;
}

void Globals::runGame()
{
	//window and view setup
	sf::RenderWindow window(sf::VideoMode(1280, 640), "Kill It With Fire!");
	window.setFramerateLimit(60);
	sf::View view(sf::FloatRect(0, 0, 1280, 640));
	window.setView(view);
	view.setCenter(640, 320);
	
	//font setup
	if(!gameFont.loadFromFile("kongtext.ttf"))
		{
		throw(42);
		}

	//tiles setup 
	for(int i = 0; i < 3; i++)
	{
	if(!textures[i].texture.loadFromFile(textures[i].fileName))
			{
			throw(42);
			}
	}

	//insert main menu screen here
	mainMenu(window);

	//map loading
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

	window.setMouseCursorVisible(false);

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
				view.move(0.0, -5.0);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			//move down
			view.move(0.0, 5.0);
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
			{
				//move left
				view.move(-5.0, 0.0);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//right
			view.move(5.0, 0.0);
		}
        window.clear();
		window.setView(view);
        drawGameMap(window);
        window.display();
    }
}

void Globals::mainMenu(sf::RenderWindow& window)
{
	Button mapMaker(&textures[1].texture, &textures[2].texture, std::string("Map Maker"), sf::Vector2f(100.0f, 530.0f), gameFont); 

	while(!mapMaker.getState())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			// left mouse button is pressed check if mutton is clicked
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			mapMaker.checkIfClick(sf::Vector2f(localPosition.x, localPosition.y));
			}

		window.clear();
		window.draw(*mapMaker.getSprite());
		window.draw(*mapMaker.getText());
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

