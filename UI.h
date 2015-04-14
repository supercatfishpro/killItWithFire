
#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI
{
private:
	bool canToggle, canDraw;
	sf::Sprite image;

public:

	UI();
	UI(bool canToggle, sf::Texture& image);

	void setPosition(float x, float y);
	//check if you can draw before drawing each time
	bool getCanDraw();

	//maybe add move location function?
	void toggle();
	sf::Sprite draw();
};

#endif
