#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game/World.hpp"
#include "Game/Render.hpp"
#include "Game/Logic.hpp"

int main()
{
    Render::resolution = sf::Vector2u(800, 800);

    const int UPDATE_PER_SECOND = 25;
    const int UPDATE_INTERVAL = 1000/UPDATE_PER_SECOND;
    const int MAX_FRAMESKIP = 5;

    Inputs inputs = Inputs();
    World world = World();
    Render render = Render();
    Logic logic = Logic();

    sf::Clock clock;
    
    double next_update_time = clock.getElapsedTime().asMilliseconds();
    int update_number;
    float interpolation;

    //Check "loop sequencing patern" for more
    while (logic.getGameState() != -1)
    {
        inputs.process();

        update_number = 0;
        while (clock.getElapsedTime().asMilliseconds() > next_update_time && update_number < MAX_FRAMESKIP)
        {
            logic.update(world);

            next_update_time += UPDATE_INTERVAL;
            update_number++;
        }

        interpolation = float(clock.getElapsedTime().asMilliseconds() + UPDATE_INTERVAL - next_update_time)/float(UPDATE_INTERVAL);
        render.display(world.getObjects(), interpolation);
    }
    
    return 0;
}