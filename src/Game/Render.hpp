#pragma once

#include "Objects/Object.hpp"

class Render {
private:

    sf::RenderWindow window;
    

public:

    static sf::Vector2u resolution;

    Render()
    : window(sf::VideoMode(resolution.x, resolution.y), "Game")
    {};

    void display(std::vector<Object>& objects, float interpolation) {
        window.clear();
        for(unsigned int i(0); i<objects.size(); i++) {
            window.draw(objects[i].refresh(interpolation));
        }
        window.display();
    }
};