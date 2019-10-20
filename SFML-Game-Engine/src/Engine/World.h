#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Entities/Entity.h"

class World {
private:
	sf::Int32 clock;

	std::vector<Entity*> entities;

public:

	World();
	~World();

	sf::Int32& getClock();
	void setClock(const sf::Int32& _clock);

	std::vector<Entity*>& getEntities();

	void addEntity(Entity* entity);
	void deleteEntity(unsigned int index);
};