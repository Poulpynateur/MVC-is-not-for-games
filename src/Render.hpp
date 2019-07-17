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