#pragma once
#include <SFML/Graphics.hpp>

#include "Inputs.hpp"
#include "World.hpp"

class Controller {
private:
    Inputs inputs;
    World world;
public:

    Controller(sf::Vector2u bounds)
    : world(bounds)
    {}

    void input() {
        inputs.process();
    }

    void logic() {
        for(unsigned int i=0; i<world.getObjects().size(); i++) {
            world.getObjects()[i].update(world);
        }
    }

    //Full class ?
    void render(sf::RenderWindow& window, float interpolation) {
        for(unsigned int i=0; i<world.getObjects().size(); i++) {
            window.draw(world.getObjects()[i].render(interpolation));
        }
        window.display();
    }
};
