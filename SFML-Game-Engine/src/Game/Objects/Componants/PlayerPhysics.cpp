#include "PlayerPhysics.h"

#include "../Player.h"

PlayerPhysics::PlayerPhysics()
	: ComponentPhysics(5)
{}

void PlayerPhysics::update(Player* parent, IWorld* world) {
	position += movement;
	parent->graphics->setPixelPosition(position);
	parent->graphics->setPixelMovement(movement);
};