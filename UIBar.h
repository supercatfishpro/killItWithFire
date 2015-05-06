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
	sf::Vector2i position;

public:
	UIBar();
	UIBar(int x, int y);
	UIBar(int maxWidth, sf::Color, int x, int y);

	void setPosition(int x, int y);
	void setWidth(int newWidth);
	void setMaxWidth();

	sf::Vector2i& getPosition();
	int getMaxWidth();
	sf::RectangleShape& getUIBar();
};

#endif
