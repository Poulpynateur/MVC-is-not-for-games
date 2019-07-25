#pragma once
#include <iostream>

class World;
class Object;

class Component {
public:
	void update(Object& object, World& world);
};