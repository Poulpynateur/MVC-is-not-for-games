#include "Component.h"
#include "../Object.h"
#include "../../World.h"

void Component::update(Object& object, World& world) {
	std::cout << "Object component + " + world.saidSomething() << '\n';
}