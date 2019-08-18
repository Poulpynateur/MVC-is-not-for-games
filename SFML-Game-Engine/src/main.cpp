#pragma warning( disable : 4244 )

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine/Controller.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Game");

	const int UPDATE_PER_SECOND = 25;
	const int UPDATE_INTERVAL = 1000 / UPDATE_PER_SECOND;
	const int MAX_FRAMESKIP = 5;

	Controller controller(window.getSize());

	sf::Clock clock;

	double next_update_time = clock.getElapsedTime().asMilliseconds();
	int update_number;
	float interpolation;
	sf::Int32 time;

	//Check "loop sequencing patern" for more
	while (window.isOpen())
	{
		//Useless for now
		//controller.input();

		update_number = 0;
		while (clock.getElapsedTime().asMilliseconds() > next_update_time && update_number < MAX_FRAMESKIP)
		{
			controller.logic(clock.getElapsedTime().asMilliseconds());

			next_update_time += UPDATE_INTERVAL;
			update_number++;
		}

		interpolation = float(clock.getElapsedTime().asMilliseconds() + UPDATE_INTERVAL - next_update_time) / float(UPDATE_INTERVAL);
		controller.render(window, interpolation);
	}

	return 0;
}