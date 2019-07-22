#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Render.hpp"
#include "Objects/Object.hpp"

#define OBJECT_NBR 50

class World {
private:
    std::vector<Object> objects;
public:
    World() {

        sf::Vector2u windowBounds = Render::resolution;

        srand (time(NULL));
        //Creating random objects
        for(int i=0; i<OBJECT_NBR; i++) {
            Object object(rand() % 10 + 5, sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10));
            object.setCoord(rand()%windowBounds.x, rand()%windowBounds.y);
            objects.push_back(object);
        }
    }

    std::vector<Object>& getObjects() {
        return objects;
    }
};