//Evan Gordon

#include "UIBar.h"

UIBar::UIBar()
{
maxWidth = 100;
bar.setSize(sf::Vector2f(maxWidth, 10));
bar.setPosition(10,10);
bar.setFillColor(sf::Color::Red);
position.x = 10;
position.y = 10;
}

UIBar::UIBar(int x, int y)
{
maxWidth = 100;
bar.setSize(sf::Vector2f(this->maxWidth, 10));
bar.setFillColor(sf::Color::Red);
bar.setPosition(x, y);
position.x = x;
position.y = y;
}

UIBar::UIBar(int maxWidth, sf::Color color, int x, int y)
{
this->maxWidth = maxWidth;
bar.setSize(sf::Vector2f(this->maxWidth, 10));
bar.setFillColor(color);
bar.setPosition(x, y);
position.x = x;
position.y = y;
}

void UIBar::setWidth(int newWidth)
{
	if(newWidth > maxWidth)
	{
	bar.setSize(sf::Vector2f(maxWidth, 10));
	}
	else
	{
	bar.setSize(sf::Vector2f(newWidth, 10));
	}
}

void UIBar::setPosition(int x, int y)
{
bar.setPosition(x,y);
position.x = x;
position.y = y;
}

void UIBar::setMaxWidth()
{
	bar.setSize(sf::Vector2f(maxWidth, 10));
}

sf::Vector2i& UIBar::getPosition()
{
	return this->position;
}
int UIBar::getMaxWidth()
{
	return maxWidth;
}
sf::RectangleShape& UIBar::getUIBar()
{
	return bar;
}