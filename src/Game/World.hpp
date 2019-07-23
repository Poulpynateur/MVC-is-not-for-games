#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include "Object/Player.hpp"

class World {
private:

    sf::Vector2u bounds;
    std::vector<Player> objects;

public:
    World(sf::Vector2u _bounds) 
    : bounds(_bounds)
    {}

    std::vector<Player>& getObjects() {
        return objects;
    }
};
