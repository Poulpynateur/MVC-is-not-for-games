#include "Engine.h"

Engine::Engine(World* _world)
	: world(_world)
{}

Engine::~Engine() {
	delete world;
}

/**** METHODS ****/

//Updating each layers
void Engine::logic(const sf::Int32& time) {

	world->setClock(time);

	for (unsigned int i = 0; i < world->getLayers().size(); i++) {
		world->getLayers()[i]->update(world);
	}
}

void Engine::render(sf::RenderWindow& render, float interpolation) {
	render.clear();
	for (unsigned int i = 0; i < world->getLayers().size(); i++) {
		world->getLayers()[i]->refresh(render, interpolation);
	}
	render.display();
}