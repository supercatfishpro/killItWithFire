//Evan Gordon

#include "CooldownBar.h"

CooldownBar::CooldownBar()
{
	cooldown = false;
	cooldownTime = sf::seconds(1);
}

CooldownBar::CooldownBar(int x, int y): UIBar(x, y)
{
	cooldown = false;
	cooldownTime = sf::seconds(1);
}

void CooldownBar::setCooldownTime(sf::Time& cooldownTime)
{
	this->cooldownTime = cooldownTime;
}

void CooldownBar::press()
{
	if(cooldown != true)
	{
	cooldown = true;
	timer = sf::seconds(0);
	}
}

sf::RectangleShape CooldownBar::draw(sf::Time& currentTime)
{
	timer = timer + currentTime;
	if(timer >= cooldownTime)
		{
		cooldown = false;
		timer = sf::seconds(0);
		this->setWidth(0);
		}
	else
		{
		this->setWidth(((cooldownTime - timer)/sf::seconds(.01)));
		}
	return getUIBar();
}

bool CooldownBar::isPressed()
{
	return cooldown;
}