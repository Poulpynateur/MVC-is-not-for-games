#pragma once
#include <SFML/Graphics.hpp>

#include "KeyListenner.hpp"
#include "World.hpp"

class Controller {
private:
    World world;
    KeyListenner keyListenner;
public:

    Controller(sf::Vector2u bounds)
    : world(bounds)
    {
        world.getObjects().push_back(Player(new PlayerInputs()));
    }

    void input() {
        keyListenner.refresh();
    }

    void logic() {
        for(unsigned int i=0; i < world.getObjects().size(); i++) {
            world.getObjects()[i].update(keyListenner.getKeys());
        }
    }

    //Full class ?
    void render(sf::RenderWindow& window, float interpolation) {

    }
};
