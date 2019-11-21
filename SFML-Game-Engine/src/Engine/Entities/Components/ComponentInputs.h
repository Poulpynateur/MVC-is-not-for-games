#pragma once

template <typename Parent>
class ComponentInputs {
public:
	virtual void update(Parent* parent, IWorld* world) = 0;
};

