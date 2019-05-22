#include <SFML/Graphics.hpp>

#include "Src/Inputs.cpp"
#include "Src/Elements.cpp"
#include "Src/Render.cpp"
#include "Src/Logic.cpp"

#include <iostream>

int main()
{
    const unsigned int WIDTH = 800;
    const unsigned int HEIGTH = 800;

    const int UPDATE_PER_SECOND = 25;
    const int UPDATE_INTERVAL = 1000/UPDATE_PER_SECOND;
    const int MAX_FRAMESKIP = 5;

    Elements* elements = new Elements(sf::Vector2u(WIDTH,HEIGTH));

    Inputs* inputs = new Inputs();
    Render* render = new Render(WIDTH, HEIGTH);
    Logic* logic = new Logic(sf::Vector2u(WIDTH,HEIGTH));

    sf::Clock clock;
    sf::Clock clock2;
    
    double next_update_time = clock.getElapsedTime().asMilliseconds();
    int update_number;
    float interpolation;

    while (inputs->getGameState() == 1)
    {
        InputsList& inputsList = inputs->get();

        update_number = 0;
        while (clock.getElapsedTime().asMilliseconds() > next_update_time && update_number < MAX_FRAMESKIP)
        {
            logic->update(elements->getObjects(), inputsList);

            next_update_time += UPDATE_INTERVAL;
            update_number++;
        }

        interpolation = float(clock.getElapsedTime().asMilliseconds() + UPDATE_INTERVAL - next_update_time)/float(UPDATE_INTERVAL);
        render->display(elements->getObjects(), interpolation);

        std::cout << clock2.restart().asMilliseconds() << '\n';
    }

    delete inputs;
    delete render;
    delete logic;
    delete elements;
    
    return 0;
}