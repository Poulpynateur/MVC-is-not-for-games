#include "Entity.h"

#include "../World.h"

Entity::Entity(sf::Shape* _shape)
	: shape(_shape), isDismised(false)
{}
Entity::Entity(sf::Shape* _shape, sf::Vector2f _position)
	: shape(_shape), position(_position), isDismised(false)
{}

Entity::~Entity() {
	delete shape;
}

/**** GETTERS and SETTERS ****/

void Entity::setDismised() {
	isDismised = true;
}
bool Entity::checkIfDismised() {
	return isDismised;
}

sf::Vector2f Entity::getPos() {
	return position;
}

void Entity::setPos(sf::Vector2f _pos) {
	position = _pos;
}
void Entity::setPos(float x, float y) {
	position.x = x;
	position.y = y;
}
void Entity::setPosX(float x) {
	position.x = x;
}
void Entity::setPosY(float y) {
	position.y = y;
}

/**** METHODS ****/

sf::Shape* Entity::refresh(float interpolation) {
	//Interpolation is used only for movement
	shape->setPosition(position);
	return shape;
}