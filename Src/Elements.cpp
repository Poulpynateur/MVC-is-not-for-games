#include "Elements.hpp"

/** Constructor **/
Elements::Elements(sf::Vector2u _windowBounds) {

    srand (time(NULL));
    for(int i=0; i<OBJECT_NBR; i++) {
        Object object(rand() % 10 + 5, sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10));
        object.setCoord(rand()%_windowBounds.x, rand()%_windowBounds.y);
        objects.push_back(object);
    }

}

/** Getters and Setters **/
std::vector<Object>& Elements::getObjects() {
    return objects;
}