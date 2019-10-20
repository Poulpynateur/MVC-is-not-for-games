#include "World.h"

World::World()
	: clock(0)
{
	srand(time(NULL)); // Set the random seed
}
World::~World() {
	for (unsigned int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}
}

/**** GETTERS and SETTERS ****/
sf::Int32& World::getClock() {
	return clock;
}
void World::setClock(const sf::Int32& _clock) {
	clock = _clock;
}

std::vector<Entity*>& World::getEntities() {
	return entities;
}

/**** METHODS ****/

void World::addEntity(Entity* entity) {
	entities.push_back(entity);
}
void World::deleteEntity(unsigned int index) {
	delete entities[index];
	entities.erase(entities.begin() + index);
}