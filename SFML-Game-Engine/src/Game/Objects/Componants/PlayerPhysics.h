#pragma once

#include "../../EngineInclude.h"

class Player;
class PlayerPhysics {

	sf::Vector2f position;
	sf::Vector2f movement;

	float speed = 1;

public:

	void update(Player* parent, World* world);

	sf::Vector2f& getPosition();

	void resetMovement();
	void moveRight();
	void moveLeft();
	void moveTop();
	void moveBottom();
};