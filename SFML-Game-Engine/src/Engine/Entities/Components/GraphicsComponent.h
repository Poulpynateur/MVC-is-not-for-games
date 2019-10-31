#pragma once

#include "Component.h"

class GraphicsComponent : public Component {
	public:
		virtual void draw(sf::RenderWindow& render, float interpolation) = 0;
};