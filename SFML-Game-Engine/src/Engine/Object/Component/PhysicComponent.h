#pragma once

#include <iostream>

class World;
class Dynamic;

class PhysicComponent {
public:
	void update(Dynamic& object, World& world);
};