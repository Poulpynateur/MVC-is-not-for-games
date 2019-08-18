#include "Object.h"

Object::Object(sf::Shape* _shape)
: shape(_shape), state(true)
{}

Object::~Object() {
	delete shape;
}

/** Getters and Setters **/
sf::Vector2f Object::getPos() {
	return position;
}
void Object::setPos(sf::Vector2f _pos) {
	position = _pos;
}
void Object::setPos(float x, float y) {
	position.x = x;
	position.y = y;
}

void Object::setState(bool _state) {
	state = _state;
}
bool Object::getState() {
	return state;
}

sf::Shape* Object::getShape() {
	return shape;
}

/* Kepp object up to date */
sf::Shape* Object::refresh() {
	shape->setPosition(position);
	return shape;
}