#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game/Controller.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Game");

    const int UPDATE_PER_SECOND = 25;
    const int UPDATE_INTERVAL = 1000/UPDATE_PER_SECOND;
    const int MAX_FRAMESKIP = 5;

    Controller controller(window.getSize());

    sf::Clock clock;
    
    double next_update_time = clock.getElapsedTime().asMilliseconds();
    int update_number;
    float interpolation;

    //Check "loop sequencing patern" for more
    while (window.isOpen())
    {
        controller.input();

        update_number = 0;
        while (clock.getElapsedTime().asMilliseconds() > next_update_time && update_number < MAX_FRAMESKIP)
        {
            controller.logic();

            next_update_time += UPDATE_INTERVAL;
            update_number++;
        }

        interpolation = float(clock.getElapsedTime().asMilliseconds() + UPDATE_INTERVAL - next_update_time)/float(UPDATE_INTERVAL);
        controller.render(window, interpolation);
    }
    
    return 0;
}