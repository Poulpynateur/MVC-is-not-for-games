#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Objects/Test.hpp"

#define OBJECT_NBR 50

class World {
private:

    sf::Vector2u bounds;
    std::vector<Object> objects;

public:
    World(sf::Vector2u _bounds) :
    bounds(_bounds)
    {
        srand (time(NULL));
        //Creating random objects
        for(int i=0; i<OBJECT_NBR; i++) {
            Test object(bounds);
            objects.push_back(object);
        }
    }

    sf::Vector2u& getBounds() {
        return bounds;
    }

    std::vector<Object>& getObjects() {
        return objects;
    }
};