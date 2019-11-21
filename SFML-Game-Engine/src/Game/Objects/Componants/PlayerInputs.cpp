#include "PlayerInputs.h"

#include "../Player.h"

/**** METHODS ****/

void PlayerInputs::update(Player* parent, IWorld* world) {

	parent->physics->resetMovement();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		parent->physics->moveTop();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		parent->physics->moveBottom();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		parent->physics->moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		parent->physics->moveRight();
	}
}
