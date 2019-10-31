#pragma once

#include <SFML/Graphics.hpp>

/*
	Define the very basic of elements of the game
*/

class World;

class Entity {
protected:

	bool dismised;

public:
	Entity();

	void setDismised();
	bool isDismised();

	virtual void draw(sf::RenderWindow& render, float interpolation) = 0;
	virtual void update(World* world) = 0;
};