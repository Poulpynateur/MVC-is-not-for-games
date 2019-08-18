#include "PlayerInputs.h"
#include "../Player.h"
#include "../../Engine/World.h"

void PlayerInputs::update(Player& player, World& world) {

	//Movements
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

	//Check key and timer
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && world.getClock() - internal_clock > fire_rate) {
		world.shootBullet(player.getSpeed(), player.getPos());
		//Reset timer
		internal_clock = world.getClock();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.setState(false);
	}
}