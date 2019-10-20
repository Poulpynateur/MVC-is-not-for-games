#pragma once

#include "Entity.h"

class Dynamic : public Entity {
protected:

	sf::Vector2f movement;

public:

	Dynamic(sf::Shape* _shape);
	Dynamic(sf::Shape* _shape, sf::Vector2f _position);

	void setMovement(sf::Vector2f _movement);
	void setMovementX(float x);
	void setMovementY(float y);

	void move(float offsetX, float offsetY);
	void move(sf::Vector2f offset);

	virtual sf::Shape* refresh(float interpolation);
	virtual void update(World* world) = 0;

	virtual void onCollision(Dynamic* origin) = 0;
};