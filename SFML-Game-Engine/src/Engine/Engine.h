#pragma once
#include <SFML/Graphics.hpp>

#include "World.h"

class Engine {
private:
	World* world;
public:
	Engine(World* _world);
	~Engine();

	void logic(const sf::Int32& clock);
	void render(sf::RenderWindow& window, float interpolation);
};