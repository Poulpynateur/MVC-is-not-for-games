#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Object.cpp"

class Render {
private:
    sf::RenderWindow window;
public:
    Render(unsigned int width, unsigned int heigth);

    void display(std::vector<Object>& objects, float interpolation);
};
/** Constructor **/
Render::Render(unsigned int width, unsigned int heigth) : window(sf::VideoMode(width, heigth), "Game")
{};

/**
 * Used in main loop to display/refresh the elements
 * elements : elements to display
 * interpolation : estimate element position between two updates
 */
void Render::display(std::vector<Object>& objects, float interpolation) {
    window.clear();
    for(unsigned int i(0); i<objects.size(); i++) {
        window.draw(objects[i].display(interpolation));
    }
    window.display();
}