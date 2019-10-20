#include "Dynamic.h"


Dynamic::Dynamic(sf::Shape* _shape)
	: Entity(_shape)
{}
Dynamic::Dynamic(sf::Shape* _shape, sf::Vector2f _position) 
	: Entity(_shape, _position)
{}

/**** GETTERS and SETTERS ****/

void Dynamic::setMovement(sf::Vector2f _movement) {
	movement = _movement;
}
void Dynamic::setMovementX(float x) {
	movement.x = x;
}
void Dynamic::setMovementY(float y) {
	movement.y = y;
}

void Dynamic::move(float offsetX, float offsetY) {
	movement.x += offsetX;
	movement.y += offsetY;
}
void Dynamic::move(sf::Vector2f offset) {
	movement += offset;
}

/**** METHODS ****/

sf::Shape* Dynamic::refresh(float interpolation) {
	shape->setPosition(position + movement * interpolation);
	position += movement;
	return shape;
}