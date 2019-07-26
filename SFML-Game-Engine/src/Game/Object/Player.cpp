#include "Player.h"

Player::Player(PhysicComponent* _physic, PlayerInputs* _inputs)
: Object(10.0, sf::Vector2f(), _physic), inputs(_inputs), max_speed(10)
{
	this->shape.setFillColor(sf::Color::Green);
}

float Player::getMaxSpeed() {
	return max_speed;
}

void Player::update(World& world) {
	Object::update(world);
	inputs->update(*this);
}