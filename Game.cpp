#include <SFML/Graphics.hpp>
#include "Utility.cpp"

#include <iostream>

#include "Src/GameLogic.cpp"
#include "Src/Elements/Elements.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Balls, balls, balls.");
    
    //Game objects
    Elements elements(window.getSize());
    //Game logic
    GameLogic logic(elements);

    sf::Clock clock;
    while (window.isOpen()) {
        logic.keyEvents(clock.restart().asMilliseconds());
        logic.movePlayer();
        logic.playerShoot();

        //render
        window.clear();
        elements.refresh(window);
        window.display();

        //std::cout << elements.getProjectiles().size() << '\n';
        std::cout << clock.getElapsedTime().asMilliseconds() << '\n';
    }

    return 0;
}