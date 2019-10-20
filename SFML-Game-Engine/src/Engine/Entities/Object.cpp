#include "Object.h"

#include "../World.h"

Object::Object(sf::Shape* _shape)
	: shape(_shape)
{}
Object::Object(sf::Shape* _shape, sf::Vector2f _position)
	: shape(_shape), position(_position)
{}

Object::~Object() {
	delete shape;
}

/**** GETTERS and SETTERS ****/

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
void Object::setPosX(float x) {
	position.x = x;
}
void Object::setPosY(float y) {
	position.y = y;
}

/**** METHODS ****/

void Object::refresh(sf::RenderWindow& render, float interpolation) {
	//Interpolation is used only for movement
	shape->setPosition(position);
	render.draw(*shape);
}