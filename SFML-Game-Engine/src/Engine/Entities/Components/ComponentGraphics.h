#pragma once

#include <SFML/Graphics.hpp>

template <typename Parent>
class ComponentGraphics  {
	 
protected:

	sf::RectangleShape* shape;

	sf::Vector2f pixelPosition;
	sf::Vector2f pixelMovement;

public:

	ComponentGraphics(sf::RectangleShape* _shape)
		: shape(_shape)
	{}
	~ComponentGraphics() {
		delete shape;
	}

	void setPixelPosition(sf::Vector2f pos) {
		pixelPosition = pos;
	}
	void setPixelMovement(sf::Vector2f mov) {
		pixelMovement = mov;
	}

	virtual void update(Parent* parent) = 0;

	sf::Shape& refresh(float interpolation) const {
		shape->setPosition(pixelPosition + pixelMovement * interpolation);
		return *shape;
	};
};