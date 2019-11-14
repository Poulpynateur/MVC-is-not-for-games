#include "PlayerInputs.h"

#include "../Player.h"

/**** METHODS ****/

void PlayerInputs::update(Player* parent, World* world) {

	parent->physics->resetMovement();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		parent->physics->moveTop();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		parent->physics->moveBottom();
	}
}
