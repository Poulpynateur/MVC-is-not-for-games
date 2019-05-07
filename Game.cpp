#include <SFML/Graphics.hpp>
#include "Utility.cpp"

#include <iostream>

#include "Src/GameLogic.cpp"
#include "Src/Elements.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Balls & shoot");
    window.setFramerateLimit(60);

    //Game objects
    Elements elements(window.getSize());
    //Game logic
    GameLogic logic;

    sf::Clock clock;
    while (window.isOpen()) {
        logic.initLoop();
        logic.keyEvents();

        logic.playerMove(elements.getPlayer());
        logic.playerShoot(elements.getPlayer(), elements.getProjectiles());

        logic.projectilesMove(elements.getProjectiles(), elements.getMap());
        /**
         * Render
         * */
        window.clear();
        elements.refresh(window);
        window.display();

        //std::cout << clock.restart().asMilliseconds() << '\n';
    }

    return 0;
}