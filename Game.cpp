#include <SFML/Graphics.hpp>

#include "Src/Action.cpp"
#include "Src/Elements/Elements.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(60);
    //Game objects
    Elements elements(window.getSize());

    //Game logic
    Action logic(elements);

    sf::Clock clock;
    while (window.isOpen()) {
        logic.setEllapsedTime(clock.restart().asMilliseconds());
        logic.movePlayer(elements);

        window.clear();
        window.draw(elements);
        window.display();
    }

    return 0;
}