#pragma once

#include <SFML/Graphics.hpp>

class PlayerGraphics {
private:

	sf::RectangleShape* shape;

public:

	PlayerGraphics()
		: shape(new sf::RectangleShape(sf::Vector2f(10,10)))
	{};

	void update(Entity* parent) {
		shape->move(1,1);
	};
	sf::Shape& refresh(float interpolation) const {
		return *shape;
	};
};