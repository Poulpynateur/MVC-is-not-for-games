#pragma once

#include "Component/Component.h"

class World;

class Object {
private:
	Component component;
public:
	void update(World& world);
};
