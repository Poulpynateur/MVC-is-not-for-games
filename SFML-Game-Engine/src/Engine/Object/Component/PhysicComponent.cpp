#include "PhysicComponent.h"
#include "../Dynamic.h"
#include "../../World.h"

void PhysicComponent::update(Dynamic& object, World& world) {

	sf::Vector2f pos = object.getPos();
	sf::Vector2u windowBounds = world.getBounds();

	if (pos.x > windowBounds.x) {
		object.setPos(0, pos.y);
	}
	else if (pos.y > windowBounds.y) {
		object.setPos(pos.x, 0);
	}
	else if (pos.x < 0) {
		object.setPos(windowBounds.x, pos.y);
	}
	else if (pos.y < 0) {
		object.setPos(pos.x, windowBounds.y);
	}
	else {
		object.move();
	}
}