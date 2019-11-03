#include "PlayerInputs.h"

#include "../Player.h"

void PlayerInputs::update(Player* parent, World* world) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		parent->graphics->shape->setPosition(0, 0);
	}
}
