//Evan Gordon

#ifndef COOLDOWNBAR_H
#define COOLDOWNBAR_H

#include "UIBar.h"

#include <SFML/Graphics.hpp>

//child class of UIBAR
class CooldownBar: public UIBar
{
	//implement inheritance of uibar
	//make uibar abstract
private:
	sf::Time cooldownTime;
	//endtime = time when button is pressed + cooldown time
	sf::Time timer;
	bool cooldown;

public:
	CooldownBar();
	CooldownBar(int x, int y);

	void setCooldownTime(sf::Time& cooldownTime);

	void press();
	sf::RectangleShape draw(sf::Time& currentTime);	//current question is whether i should do the drawing and handling of this bar inside the character class or globals class

	bool isPressed();
};

#endif