#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include <stdexcept>
#include <string>

class Button {
private:
    sf::Sprite normal;
    sf::Sprite clicked;
    sf::Sprite* currentSpr;
    sf::Text text;
	sf::Font* font;
    bool isPushed;

public:
	Button(sf::Texture* normal, sf::Texture* clicked, sf::Vector2f location);
    Button (sf::Texture* normal, sf::Texture* clicked, std::string text, sf::Vector2f location, sf::Font* font);

    bool checkIfClick (sf::Vector2f* mousePos);
    void setState(bool);
    void setText(std::string);

    bool getState();
    sf::Sprite* getSprite();
    sf::Text* getText();
};

#endif