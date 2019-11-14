#include "PlayerGraphics.h"

#include "../Player.h"

PlayerGraphics::PlayerGraphics()
	: shape(new sf::RectangleShape(sf::Vector2f(10, 10)))
{};

/**** GETTERS and SETTERS ****/

void PlayerGraphics::setPixelPosition(sf::Vector2f pos) {
	pixelPosition = pos;
}
void PlayerGraphics::setPixelMovement(sf::Vector2f mov) {
	pixelMovement = mov;
}

/**** Update ****/

void PlayerGraphics::update(Player* parent) {

};

sf::Shape& PlayerGraphics::refresh(float interpolation) const {
	shape->setPosition(pixelPosition + pixelMovement*interpolation);
	return *shape;
};