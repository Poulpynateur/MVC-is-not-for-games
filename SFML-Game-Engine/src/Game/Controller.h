#pragma once
#include <SFML/Graphics.hpp>

#include "KeyListenner.h"
#include "World.h"

class Controller {
private:
	World world;
	KeyListenner keyListenner;
public:

	Controller(sf::Vector2u bounds)
	{

	}

	void input() {
		keyListenner.refresh();
	}

	void logic() {

	}

	//Full class ?
	void render(sf::RenderWindow& window, float interpolation) {

	}
};