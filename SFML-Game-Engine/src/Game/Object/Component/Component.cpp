#include "PhysicComponent.h"
#include "../Object.h"
#include "../../World.h"

void PhysicComponent::update(Object& object, World& world) {
	std::cout << "Object component + " + world.saidSomething() << '\n';
}