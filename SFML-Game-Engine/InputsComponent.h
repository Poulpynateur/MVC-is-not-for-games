#pragma once

#include <iostream>

class World;
class Object;

class InputsComponent {
public:
	void update(Object& object, World& world);
};