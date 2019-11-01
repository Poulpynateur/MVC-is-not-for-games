#include "World.h"

World::World()
	: clock(0)
{
	srand(time(NULL)); // Set the random seed

	for (int i = 0; i != Layer::last; i++) {
		layers.push_back(new Group());
	}
	
}
World::~World() {
	for (auto layer : layers) {
		delete layer;
	}
	layers.clear();
}

/**** GETTERS and SETTERS ****/
sf::Int32& World::getClock() {
	return clock;
}
void World::setClock(const sf::Int32& _clock) {
	clock = _clock;
}

/**** METHODS ****/
void World::addEntity(Layer target_layer, Entity* entity) {
	layers[target_layer]->getChildrens().push_back(entity);
}

std::vector<Group*>& World::getLayers() {
	return layers;
}