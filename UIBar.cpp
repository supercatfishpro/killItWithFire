//Evan Gordon

#include "UIBar.h"

UIBar::UIBar()
{
maxWidth = 100;
bar.setSize(sf::Vector2f(maxWidth, 10));
bar.setPosition(10,10);
bar.setFillColor(sf::Color::Red);
}

UIBar::UIBar(int maxWidth, sf::Color color)
{
this->maxWidth = maxWidth;
bar.setSize(sf::Vector2f(this->maxWidth, 10));
bar.setFillColor(color);
bar.setPosition(10,10);
}

void UIBar::setWidth(int newWidth)
{
	bar.setSize(sf::Vector2f(newWidth, 10));	
}

void UIBar::setPosition(int x, int y)
{
bar.setPosition(x,y);
}

sf::RectangleShape& UIBar::getUIBar()
{
	return bar;
}