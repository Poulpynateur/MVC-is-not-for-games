#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"

class Controller {
private:
	World world;
public:

	Controller(sf::Vector2u bounds)
	: world(bounds)
	{

	}

	void logic() {
		for (unsigned int i(0); i < world.getObjects().size(); i++) {
			world.getObjects()[i]->update(world);
		}
	}

	//Full class ?
	void render(sf::RenderWindow& window, float interpolation) {
		window.clear();
		for (unsigned int i(0); i < world.getObjects().size(); i++) {
			window.draw(world.getObjects()[i]->refresh(interpolation));
		}
		window.display();
	}
};