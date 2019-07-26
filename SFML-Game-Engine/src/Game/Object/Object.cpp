#include "Object.h"
#include "../world.h"

Object::Object(float radius, sf::Vector2f _movement, PhysicComponent* _physic)
: shape(radius), speed(_movement), physic(_physic)
{}

/** Getters and Setters **/
sf::Vector2f Object::getPos() {
	return position;
}

void Object::setPos(float x, float y) {
	position.x = x;
	position.y = y;
}

sf::Vector2f Object::getSpeed() {
	return speed;
}

void Object::setSpeedX(float x) {
	speed.x = x;
}
void Object::setSpeedY(float y) {
	speed.y = y;
}

void Object::move() {
	position += speed;
}

/* Kepp object up to date */
sf::CircleShape& Object::refresh(float interpolation) {
	shape.setPosition(position.x + speed.x * interpolation, position.y + speed.y * interpolation);
	return shape;
}

void Object::update(World& world) {
	physic->update(*this, world);
}