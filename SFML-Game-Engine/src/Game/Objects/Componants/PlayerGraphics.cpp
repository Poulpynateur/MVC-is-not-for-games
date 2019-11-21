#include "PlayerGraphics.h"

#include "../Player.h"

PlayerGraphics::PlayerGraphics()
	: ComponentGraphics(new sf::RectangleShape(sf::Vector2f(10, 10)))
{};

/**** Update ****/

void PlayerGraphics::update(Player* parent) {
};