#pragma once

#include "../../EngineInclude.h"

class Player;
class PlayerPhysics {

	sf::Vector2f position;
	sf::Vector2f movement;

	float speed = 10;

public:

	void update(Player* parent, World* world);

	void resetMovement();
	void moveRight();
	void moveLeft();
	void moveTop();
	void moveBottom();
};