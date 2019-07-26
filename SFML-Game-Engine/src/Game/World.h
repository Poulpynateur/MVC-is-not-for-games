#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Object/Object.h"
#include "Object/Player.h"

#define OBJECT_NBR 50

class World {
private:

	sf::Vector2u bounds;
	std::vector<Object*> objects;

public:

	World(sf::Vector2u _bounds)
	: bounds(_bounds)
	{
		/*
		srand(time(NULL));
		//Creating random objects
		for (int i = 0; i < OBJECT_NBR; i++) {
			float radius = rand() % 10 + 5;
			sf::Vector2f speed = sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10);
			Object* object = new Object(radius, speed, new PhysicComponent());
			object->setPos(rand() % bounds.x, rand() % bounds.y);
			objects.push_back(object);
		}*/

		objects.push_back(new Player(new PhysicComponent(), new PlayerInputs()));
	}

	std::vector<Object*>& getObjects() {
		return objects;
	}

	sf::Vector2u& getBounds() {
		return bounds;
	}
};
