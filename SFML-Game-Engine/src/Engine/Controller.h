#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"

class Controller {
private:
	World world;
public:

	Controller(sf::Vector2u bounds)
	: world(bounds)
	{}

	void logic(sf::Int32 time) {

		world.setClock(time);

		for (unsigned int i=0; i < world.getDynamics().size(); i++) {
			Dynamic* dynamic = world.getDynamics()[i];
			dynamic->update(world);

			//If is dead
			if (dynamic->getState() == false)
				world.deleteDynamic(i);
		}
	}

	//Full class ?
	void render(sf::RenderWindow& window, float interpolation) {
		window.clear();
		for (unsigned int i=0; i < world.getStatics().size(); i++) {
			window.draw(*world.getStatics()[i]->refresh());
		}
		for (unsigned int i=0; i < world.getDynamics().size(); i++) {
			window.draw(*world.getDynamics()[i]->refresh(interpolation));
		}
		window.display();
	}
};