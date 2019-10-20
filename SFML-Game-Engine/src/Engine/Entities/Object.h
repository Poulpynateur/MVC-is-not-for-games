#pragma once

#include "Entity.h"

class Object : public Entity {
private:

	sf::Vector2f position;
	sf::Shape* shape;

public:
	Object(sf::Shape* _shape);
	Object(sf::Shape* _shape, sf::Vector2f _position);
	~Object();

	sf::Vector2f getPos();

	void setPos(sf::Vector2f _pos);
	void setPos(float x, float y);
	void setPosX(float x);
	void setPosY(float y);

	virtual void refresh(sf::RenderWindow& render, float interpolation);
	virtual void update(World* world) = 0;
};

