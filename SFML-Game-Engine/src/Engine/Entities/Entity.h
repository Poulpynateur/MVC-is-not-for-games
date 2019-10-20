#pragma once

#include <SFML/Graphics.hpp>

/*
	Define the very basic of the objects
*/

class World;

class Entity {
protected:
	bool isDismised;

	sf::Vector2f position;
	sf::Shape* shape;

public:
	Entity(sf::Shape* _shape);
	Entity(sf::Shape* _shape, sf::Vector2f _position);
	~Entity();

	void setDismised();
	bool checkIfDismised();

	sf::Vector2f getPos();

	void setPos(sf::Vector2f _pos);
	void setPos(float x, float y);
	void setPosX(float x);
	void setPosY(float y);

	virtual sf::Shape* refresh(float interpolation);
	virtual void update(World* world) = 0;
};