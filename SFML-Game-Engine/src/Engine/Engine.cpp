#include "Engine.h"

Engine::Engine(World* _world)
	: world(_world)
{}

Engine::~Engine() {
	delete world;
}

/**** METHODS ****/

void Engine::logic(const sf::Int32& time) {

	world->setClock(time);

	for (unsigned int i = 0; i < world->getEntities().size(); i++) {
		Entity* entity = world->getEntities()[i];
		entity->update(world);

		if (entity->checkIfDismised())
			world->deleteEntity(i);
	}
}

void Engine::render(sf::RenderWindow& window, float interpolation) {
	window.clear();
	for (unsigned int i = 0; i < world->getEntities().size(); i++) {
		window.draw(*world->getEntities()[i]->refresh(interpolation));
	}
	window.display();
}