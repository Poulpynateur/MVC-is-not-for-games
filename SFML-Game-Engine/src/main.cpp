#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine/Engine.h"
#include "Game/Game.h"

int main()
{
	const int UPDATE_PER_SECOND = 50;
	const int UPDATE_INTERVAL = 1000 / UPDATE_PER_SECOND;
	const int MAX_UPDATES = 5;

	Game game = Game("Test", 800, 800);
	Engine engine = Engine(game.buildWorld());

	sf::RenderWindow window(sf::VideoMode(game.resolution.x, game.resolution.y), game.name);
	sf::Clock clock;

	double next_update_time = clock.getElapsedTime().asMilliseconds();
	int update_number;
	float interpolation;

	float interpo_time_elapsed;

	while (window.isOpen()) {

		update_number = 0;
		while (clock.getElapsedTime().asMilliseconds() > next_update_time && update_number < MAX_UPDATES)
		{
			engine.logic(clock.getElapsedTime().asMilliseconds());

			next_update_time += UPDATE_INTERVAL;
			update_number++;
		}

		interpo_time_elapsed = clock.getElapsedTime().asMilliseconds() + UPDATE_INTERVAL - next_update_time;
		interpolation = interpo_time_elapsed / UPDATE_INTERVAL;

		engine.render(window, interpolation);
	}

	return 0;
}