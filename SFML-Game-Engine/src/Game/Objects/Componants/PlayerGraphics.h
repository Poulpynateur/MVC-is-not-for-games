#pragma once

#include <SFML/Graphics.hpp>

class Player;
class PlayerGraphics {

	sf::RectangleShape* shape;

	sf::Vector2f pixelPosition;
	sf::Vector2f pixelMovement;

public:
	
	PlayerGraphics();

	void setPixelPosition(sf::Vector2f pos);
	void setPixelMovement(sf::Vector2f mov);

	void update(Player* parent);
	sf::Shape& refresh(float interpolation) const;
};