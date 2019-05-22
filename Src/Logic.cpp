#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Object.cpp"
#include "Inputs.cpp"

class Logic {
private:
    //In pixel
    sf::Vector2u windowBounds;
public:
    Logic(sf::Vector2u _windowBounds);

    void update(std::vector<Object>& objects, InputsList inputsList);
};
/** Constructor **/
Logic::Logic(sf::Vector2u _windowBounds) : windowBounds(_windowBounds)
{}

/**
 * Used in main loop to update elements logic
 * elements : elements to update
 * inputsList : list of inputs
 */
void Logic::update(std::vector<Object>& objects, InputsList inputsList) {
    for(unsigned int i(0); i<objects.size(); i++) {
        sf::Vector2f pos = objects[i].getLogicPosition();
        if(pos.x > windowBounds.x) {
            objects[i].updatePosition(0, pos.y);
        }
        else if(pos.y > windowBounds.y) {
            objects[i].updatePosition(pos.x, 0);
        }
        else if(pos.x < 0) {
            objects[i].updatePosition(windowBounds.x, pos.y);
        }
        else if(pos.y < 0) {
            objects[i].updatePosition(pos.x, windowBounds.y);
        }
        else {
            objects[i].updateMove();
        }
    }
}