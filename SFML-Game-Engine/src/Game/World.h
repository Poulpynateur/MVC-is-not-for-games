#pragma once
#include <SFML/Graphics.hpp>

#include <string>

#include "Object/Object.h"

class World
{
private:
	Object object;
public:

	std::string saidSomething() {
		return "this is from world";
	}

	void doSomething() {
		object.update(*this);
	}
};
