#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>

#include "Object.h"
#include "Component/PhysicComponent.h"

class World;

class Dynamic : public Object {
protected:

	//Pixel to move each update
	sf::Vector2f speed;
	PhysicComponent* physic;

public:
	Dynamic(sf::Shape* _shape, PhysicComponent* _physic);
	~Dynamic();

	sf::Vector2f getSpeed();

	void setSpeedX(float x);
	void setSpeedY(float y);

	void move();

	//Refresh display to render
	virtual sf::Shape* refresh(float interpolation);
	//Refresh logic of the element (? Handle time)
	virtual void update(World& world);
};
