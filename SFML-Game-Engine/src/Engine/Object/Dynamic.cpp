#include "Dynamic.h"
#include "../World.h"

Dynamic::Dynamic(sf::Shape* _shape, PhysicComponent* _physic)
: Object(_shape), physic(_physic)
{}
Dynamic::~Dynamic() {
	delete physic;
}

/** Getters and Setters **/

sf::Vector2f Dynamic::getSpeed() {
	return speed;
}

void Dynamic::setSpeedX(float x) {
	speed.x = x;
}
void Dynamic::setSpeedY(float y) {
	speed.y = y;
}

void Dynamic::move() {
	position += speed;
}

/* Kepp Dynamic up to date */
sf::Shape* Dynamic::refresh(float interpolation) {
	shape->setPosition(position.x + speed.x * interpolation, position.y + speed.y * interpolation);
	return shape;
}

void Dynamic::update(World& world) {
	physic->update(*this, world);
}