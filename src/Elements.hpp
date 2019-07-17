#pragma once
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <SFML/Graphics.hpp>
#include "Objects/Object.cpp"

#define OBJECT_NBR 1000

class Elements {
private:
    std::vector<Object> objects;
public:
    Elements(sf::Vector2u _windowBounds);

    std::vector<Object>& getObjects();
};