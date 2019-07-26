#pragma once

#include <iostream>

class World;
class Object;

class PhysicComponent {
public:
	void update(Object& object, World& world);
};