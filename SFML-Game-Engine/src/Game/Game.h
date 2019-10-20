#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "EngineInclude.h"

class Game {
private:
	World* world;
public:

	sf::String name;
	sf::Vector2u resolution;

	Game(sf::String name, unsigned int resolutionX, unsigned int resolutionY);
	~Game();

	World* buildWorld();
};