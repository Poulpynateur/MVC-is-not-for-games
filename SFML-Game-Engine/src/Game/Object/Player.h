#pragma once

#include "Object.h"
#include "Component/PlayerInputs.h"

class Player : public Object {
private:
	float max_speed;
	PlayerInputs* inputs;
public:
	Player(PhysicComponent* _physic, PlayerInputs* inputs);

	float getMaxSpeed();

	void update(World& world);
};