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
/** Constructor **/
Elements::Elements(sf::Vector2u _windowBounds) {

    srand (time(NULL));
    for(int i=0; i<OBJECT_NBR; i++) {
        Object object(rand() % 10 + 5, sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10));
        object.updatePosition(rand()%_windowBounds.x, rand()%_windowBounds.y);
        objects.push_back(object);
    }
}

/** Getters and Setters **/
std::vector<Object>& Elements::getObjects() {
    return objects;
}