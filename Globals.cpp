//Evan Gordon

#include "globals.h"
#include <iostream>

//remove later and replace w menu object
#include "UI.h"

Globals::Globals()
{
	textures[0].fileName = "overWorld.png";
	textures[1].fileName = "menuButton.png";
	textures[2].fileName = "menuButtonPressed.png";
	cameraPosition.x = 0;
	cameraPosition.y = 0;
	gameMode = 0;
}

Globals::Globals(int mapx,int mapy, int cameraX, int cameraY)
{
	textures[0].fileName = "overWorld.png";
	textures[1].fileName = "menuButton.png";
	textures[2].fileName = "menuButtonPressed.png";
	gameMap.setDefaultTiles(textures[0].texture);

	cameraPosition.x = cameraX;
	cameraPosition.y = cameraY;
	gameMode = 0;
}

void Globals::initializeGame()
{
	//window and view setup
	window.create(sf::VideoMode(1280, 640), "Kill It With Fire!");
	window.setFramerateLimit(60);
	view = sf::View(sf::FloatRect(0, 0, 1280, 640));
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
	mainMenu();

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
	
	if(gameMode == 1)
	{
		runGame();
	}
	else
	{
		runMapMaker();
	}	
}


void Globals::runMapMaker()
{
	sf::Texture menuTexture;
	if(!menuTexture.loadFromFile("mapMakerMenu.png"))
			{
			throw(42);
			}
	UI itemMenu(true, menuTexture);
	itemMenu.setPosition(1132.0, 0);
	itemMenu.toggle();

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
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
		itemMenu.toggle();
		}
        window.clear();
		window.setView(view);
        drawGameMap();
		if(itemMenu.getCanDraw())
		{
			window.draw(itemMenu.draw());
		}
        window.display();
    }
}

void Globals::runGame()
{
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
        drawGameMap();
        window.display();
    }
}

void Globals::mainMenu()
{
	Button mapMaker(&textures[1].texture, &textures[2].texture, std::string("Map Maker"), sf::Vector2f(100.0f, 580.0f), &gameFont); 
	Button playGame(&textures[1].texture, &textures[2].texture, std::string("Play!"), sf::Vector2f(350.0f, 580.0f), &gameFont);

	int countDown = 0;
	while(countDown < 10)
	{
		if(countDown > 0)
		{
			countDown++;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && countDown == 0)
			{
			// left mouse button is pressed check if mutton is clicked
			bool clicked = false;
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			clicked = mapMaker.checkIfClick(&sf::Vector2f(localPosition.x, localPosition.y));
			if(clicked)
				{
				gameMode = 2;
				countDown = 1;
				}
				else
				{
				clicked = playGame.checkIfClick(&sf::Vector2f(localPosition.x, localPosition.y));
				if(clicked)
					{
					gameMode = 1;
					countDown = 1;
					}
				}
			}

		window.clear();
		window.draw(*mapMaker.getSprite());
		window.draw(*mapMaker.getText());
		window.draw(*playGame.getSprite());
		window.draw(*playGame.getText());
		window.display();
	}
}

void Globals::drawGameMap()
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

