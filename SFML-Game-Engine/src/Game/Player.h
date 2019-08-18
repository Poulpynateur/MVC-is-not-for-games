#pragma once

#include "../Engine/Object/Dynamic.h"
#include "Component/PlayerInputs.h"

class Player : public Dynamic {
private:

	PlayerInputs* inputs;

	const float max_speed = 10;
	const float inertie = 50;

public:
	Player(PhysicComponent* _physic, PlayerInputs* _inputs);
	~Player();

	float getMaxSpeed();
	float getInertie();

	void update(World& world);
};