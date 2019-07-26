#include "PlayerInputs.h"
#include "../Player.h"
#include "../../World.h"

void PlayerInputs::update(Player& player) {

	player.setSpeedX(0);
	player.setSpeedY(0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player.setSpeedY(-player.getMaxSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player.setSpeedY(player.getMaxSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.setSpeedX(-player.getMaxSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player.setSpeedX(player.getMaxSpeed());
	}
}