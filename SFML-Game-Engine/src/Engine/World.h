#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Entities/Group.h"
#include "Layer.h"

//Object access interface
class IWorld {
public:
	virtual std::vector<Group*>& getLayers() = 0;
	virtual void addEntity(Layer target_layer, Entity* entity) = 0;
};

class World : public IWorld{
private:
	sf::Int32 clock;

	std::vector<Group*> layers;

public:

	World();
	~World();

	sf::Int32& getClock();
	void setClock(const sf::Int32& _clock);

	std::vector<Group*>& getLayers();
	void addEntity(Layer target_layer, Entity* entity);
};