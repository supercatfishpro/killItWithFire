//Evan Gordon

#include "globals.h"

Globals::Globals()
{
	Globals::textures[0].fileName = "overWorld.png";
	Globals::textures[1].fileName = "menuButton.png";
	Globals::textures[2].fileName = "menuButtonPressed.png";
	Globals::textures[3].fileName = "king.png";
	Globals::textures[4].fileName = "titleScreen.png";
	gameMode = 0;
}

Globals::Globals(int mapx,int mapy, int cameraX, int cameraY)
{
	Globals::textures[0].fileName = "overWorld.png";
	Globals::textures[1].fileName = "menuButton.png";
	Globals::textures[2].fileName = "menuButtonPressed.png";
	Globals::textures[3].fileName = "king.png";
	Globals::textures[4].fileName = "titleScreen.png";
	cameraPosition.x = cameraX;
	cameraPosition.y = cameraY;
	gameMode = 0;
}

void Globals::initializeGame()
{
	//window and view setup
	Globals::window.create(sf::VideoMode(1280, 640), "Kill It With Fire!");
	Globals::window.setFramerateLimit(60);
	Globals::window.setKeyRepeatEnabled(false);
	Globals::view = sf::View(sf::FloatRect(0, 0, 1280, 640));
	Globals::userInterface = sf::View(sf::FloatRect(0, 0, 1280, 640));
	Globals::window.setView(view);
	Globals::view.setCenter(640, 320);
	Globals::cameraPosition = Globals::window.getPosition();

	//font setup
	if(!gameFont.loadFromFile("kongtext.ttf"))
	{
		throw(42);
	}

	//tiles setup 
	for(int i = 0; i < 5; i++)
	{
		if(!Globals::textures[i].texture.loadFromFile(Globals::textures[i].fileName))
		{
			throw(42);
		}
	}

	//create character
	player = Character(textures[3].texture);
	player.setSpritePostion(sf::Vector2f(640, 320));
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

	Globals::window.setMouseCursorVisible(false);

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
	//create another view for the ui?
	sf::Texture menuTexture;
	if(!menuTexture.loadFromFile("mapMakerMenu.png"))
	{
		throw(42);
	}
	UI itemMenu(true, menuTexture);
	itemMenu.setPosition(1132.0, 0);
	itemMenu.toggle();

	//game loop
	while (Globals::window.isOpen())
	{
		while (Globals::window.pollEvent(Globals::event))
		{
			switch(Globals::event.type)
			{
			case sf::Event::Closed:
				Globals::window.close();
				break;
			case sf::Event::KeyPressed:
				if(Globals::event.key.code == sf::Keyboard::Tab)
				{
				itemMenu.toggle();
				}
				else if(Globals::event.key.code == sf::Keyboard::E)
				{
				//this is gonna need some work. currently does nothing
				player.attack();
				}
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
				Globals::view.move(0.0, -5.0);
				Globals::cameraPosition = Globals::window.getPosition();
				player.setOrientation(3);

			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			//move down
			Globals::view.move(0.0, 5.0);
			Globals::cameraPosition = Globals::window.getPosition();
			player.setOrientation(0);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
			{
				//move left
				Globals::view.move(-5.0, 0.0);
				Globals::cameraPosition = Globals::window.getPosition();
				player.setOrientation(1);
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//move right
			Globals::view.move(5.0, 0.0);
			Globals::cameraPosition = Globals::window.getPosition();
			player.setOrientation(2);
		}

		Globals::window.clear();
		Globals::window.setView(Globals::view);
		drawGameMap();
		Globals::window.setView(Globals::userInterface);
		Globals::window.draw(player.getSprite());
		if(itemMenu.getCanDraw())
		{
			Globals::window.draw(itemMenu.draw());
		}
		Globals::window.display();
	}
}

void Globals::runGame()
{
	//game loop
	while (Globals::window.isOpen())
	{
		while (Globals::window.pollEvent(Globals::event))
		{
			switch(Globals::event.type)
			{
			case sf::Event::Closed:
				Globals::window.close();
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
				Globals::view.move(0.0, -5.0);
				Globals::cameraPosition = Globals::window.getPosition();
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			//move down
			Globals::view.move(0.0, 5.0);
			Globals::cameraPosition = Globals::window.getPosition();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
			{
				//move left
				Globals::view.move(-5.0, 0.0);
				Globals::cameraPosition = Globals::window.getPosition();
			}
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//right
			Globals::view.move(5.0, 0.0);
			Globals::cameraPosition = Globals::window.getPosition();
		}
		Globals::window.clear();
		Globals::window.setView(Globals::view);
		drawGameMap();
		Globals::window.display();
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
			sf::Vector2i localPosition = sf::Mouse::getPosition(Globals::window);
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

		Globals::window.clear();
		Globals::window.draw(sf::Sprite(textures[4].texture));
		Globals::window.draw(*mapMaker.getSprite());
		Globals::window.draw(*mapMaker.getText());
		Globals::window.draw(*playGame.getSprite());
		Globals::window.draw(*playGame.getText());
		Globals::window.display();
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
				Globals::window.draw(gameMap.getSprite(i, j));
			}
		}
	}
}

sf::Texture Globals::getTexture(int textureNumb)
{
	if(textureNumb < sizeof(textures))
		{
		return textures[textureNumb].texture;
		}
	else
		{
		std::cout<<"error getting texture number: "<< textureNumb << " using texture 1 instead.";
		return textures[0].texture;
		}
}

//static globals variables
sf::RenderWindow Globals::window;
sf::Event Globals::event;
sf::View Globals::view;
sf::View Globals::userInterface;
sf::Vector2i Globals::cameraPosition;
sf::Font Globals::gameFont;