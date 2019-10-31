#pragma once
#include "../Object.h"

class Component {
public:
	virtual void update(Object& parent, World* world) = 0;
};

