//Evan Gordon

#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
	weaponCooldownBar = CooldownBar(10, 20);
}

PlayerCharacter::PlayerCharacter(sf::Texture& texture): Character(texture)
{
	weaponCooldownBar = CooldownBar(10, 20);
}

int PlayerCharacter::attack(sf::Time& gameTime)
{
	weaponCooldownBar.press();
	//more to be added
	//returns an int to declare to globals what type of particle is desired?
	return -1;
}

void PlayerCharacter::draw(sf::RenderWindow& window, sf::Clock& gameClock)
{
	window.draw(this->getSprite());
	if(weaponCooldownBar.isPressed())
	{
	window.draw(weaponCooldownBar.draw(gameClock.getElapsedTime()));
	}
}