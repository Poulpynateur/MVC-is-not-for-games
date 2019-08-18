#include "Player.h"
#include "../Engine/World.h"

Player::Player(PhysicComponent* _physic, PlayerInputs* _inputs)
: Dynamic(new sf::CircleShape(10), _physic), inputs(_inputs)
{
	shape->setFillColor(sf::Color::Green);
}
Player::~Player() {
	delete inputs;
}

float Player::getMaxSpeed() {
	return max_speed;
}
float Player::getInertie() {
	return inertie;
}

void Player::update(World& world) {
	Dynamic::update(world);
	inputs->update(*this, world);
}