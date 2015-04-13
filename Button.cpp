#include "Button.h"

Button::Button(sf::Texture* normal, sf::Texture* clicked, sf::Vector2f location)
{
    this->normal.setTexture(*normal);
    this->clicked.setTexture(*clicked);
    this->currentSpr = &this->normal;
    isPushed = false;
    this->normal.setPosition(location);
    this->clicked.setPosition(location);
}

Button::Button(sf::Texture* normal, sf::Texture* clicked, std::string text, sf::Vector2f location, sf::Font font)
{
    this->normal.setTexture(*normal);
    this->clicked.setTexture(*clicked);
    this->currentSpr = &this->normal;
    isPushed = false;
    this->normal.setPosition(location);
    this->clicked.setPosition(location);  

	//string for button
    this->text.setString(text);
    this->text.setPosition(location.x + 3, location.y + 3);
    this->text.setCharacterSize(14);
	this->text.setColor(sf::Color::Blue);
}

void Button::checkIfClick (sf::Vector2f mousePos)
{
    if (mousePos.x > currentSpr->getPosition().x && mousePos.x<(currentSpr->getPosition().x + currentSpr->getLocalBounds().width)) 
	{
        if(mousePos.y>currentSpr->getPosition().y && mousePos.y<(currentSpr->getPosition().y + currentSpr->getLocalBounds().height)) 
		{
            setState(!isPushed);
        }
    }
}
void Button::setState(bool currentState) 
{
	isPushed = currentState;

    if (isPushed) 
	{
        currentSpr = &clicked;
    }
	else
	{
    currentSpr = &normal;
	}
}
void Button::setText(std::string text) 
{
   this->text.setString(text);
}
bool Button::getState() 
{
    return isPushed;
}
sf::Sprite* Button::getSprite() 
{
    return currentSpr;
}

sf::Text* Button::getText() 
{
    return &text;
}