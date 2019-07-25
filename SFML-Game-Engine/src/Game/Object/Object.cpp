#include "Object.h"
#include "../world.h"

void Object::update(World& world) {
	component.update(*this, world);
}