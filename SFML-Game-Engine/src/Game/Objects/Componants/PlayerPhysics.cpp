#include "PlayerPhysics.h"

#include "../Player.h"

void PlayerPhysics::update(Player* parent, World* world) {
	position += movement;
	parent->graphics->setPixelPosition(position);
	parent->graphics->setPixelPosition(movement);
};

sf::Vector2f& PlayerPhysics::getPosition() {
	return position;
}

/** Movement **/

void PlayerPhysics::resetMovement() {
	movement = sf::Vector2f();
}
void PlayerPhysics::moveRight() {
	movement.x = speed;
}
void PlayerPhysics::moveLeft() {
	movement.x = -speed;
}
void PlayerPhysics::moveTop() {
	movement.y = -speed;
}
void PlayerPhysics::moveBottom() {
	movement.y = speed;
}