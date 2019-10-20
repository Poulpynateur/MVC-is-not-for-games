#pragma once

#include "Entity.h"

class Group : public Entity {

private:

	std::vector<Entity*> childrens;

public:

	~Group();

	std::vector<Entity*>& getChildrens();

	virtual void refresh(sf::RenderWindow& render, float interpolation);
	virtual void update(World* world);
};

