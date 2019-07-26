#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>

#include "Component/PhysicComponent.h"

class World;

class Object {
protected:

	sf::Vector2f position;
	//Pixel to move each update
	sf::Vector2f speed;
	
	sf::CircleShape shape;

	PhysicComponent* physic;

public:
	Object(float radius, sf::Vector2f _movement, PhysicComponent* _physic);

	sf::Vector2f getPos();
	void setPos(float x, float y);

	sf::Vector2f getSpeed();

	void setSpeedX(float x);
	void setSpeedY(float y);

	void move();

	//Refresh display to render
	sf::CircleShape& refresh(float interpolation);
	//Refresh logic of the element (? Handle time)
	virtual void update(World& world);
};
