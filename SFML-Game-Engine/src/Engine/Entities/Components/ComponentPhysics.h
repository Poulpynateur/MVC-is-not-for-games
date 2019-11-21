#pragma once

#include <SFML/Graphics.hpp>

template <typename Parent>
class ComponentPhysics {

protected:

	sf::Vector2f position;
	sf::Vector2f movement;

	float max_speed;

public:

	ComponentPhysics(float _max_speed) {
		max_speed = _max_speed;
	}

	virtual void update(Parent* parent, IWorld* world) = 0;

	void resetMovement() {
		movement = sf::Vector2f();
	}
	void moveRight() {
		movement.x = max_speed;
	}
	void moveLeft() {
		movement.x = -max_speed;
	}
	void moveTop() {
		movement.y = -max_speed;
	}
	void moveBottom() {
		movement.y = max_speed;
	}
};

