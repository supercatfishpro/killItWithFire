//Evan Gordon

#ifndef UIBAR_H
#define UIBAR_H

#include <SFML/Graphics.hpp>

//abstract class to be used for both the health bar and cooldown menu bars
class UIBar
{
private:
	int maxWidth;
	sf::RectangleShape bar;

public:
	UIBar();
	UIBar(int maxWidth, sf::Color);

	void setPosition(int x, int y);
	void setWidth(int newWidth);

	sf::RectangleShape& getUIBar();
};

#endif
