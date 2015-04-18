
#include "UI.h"

UI::UI()
{
	this->canDraw = true;
	this->canToggle = true;
}

UI::UI(bool canToggle, sf::Texture& image)
{
	this->canDraw = true;
	this->canToggle = canToggle;
	this->image = sf::Sprite(image);
}


void UI::setPosition(float x, float y)
{
	image.setPosition(x, y);
}

void UI::toggle()
{
	if(canToggle)
	{
		if(canDraw)
		{
			this->canDraw = false;
		}
		else
		{
			this->canDraw = true;
		}
	}
}

sf::Sprite UI::draw()
{
	return image;
}

bool UI::getCanDraw()
{
	return canDraw;
}