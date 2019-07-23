#pragma once
#include <SFML/Graphics.hpp>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Object.hpp"
#include "Components/PhysicComponent.hpp"

class Test : public Object{
private:

    PhysicComponent pyshic;

public:
    Test(sf::Vector2u _bounds)
    : Object(rand() % 10 + 5, sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10))
    {}

    void update(World& world) {
        pyshic.update(*this, world.getBounds());
    }
};