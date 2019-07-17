#include "Logic.hpp"

/** Constructor **/
Logic::Logic(sf::Vector2u _windowBounds) : windowBounds(_windowBounds) {
    game_state = 0;
}

/** Getters and Setters **/
int Logic::getGameState() {
    return game_state;
}
void Logic::setInputList(InputsList& _inputsList) {
    inputsList = _inputsList;
}

/**
 * Used in main loop to update elements logic
 * elements : elements to update
 * inputsList : list of inputs
 */
void Logic::update(std::vector<Object>& objects) {
    for(unsigned int i(0); i<objects.size(); i++) {
        sf::Vector2f pos = objects[i].getPosition();
        if(pos.x > windowBounds.x) {
            objects[i].setCoord(0, pos.y);
        }
        else if(pos.y > windowBounds.y) {
            objects[i].setCoord(pos.x, 0);
        }
        else if(pos.x < 0) {
            objects[i].setCoord(windowBounds.x, pos.y);
        }
        else if(pos.y < 0) {
            objects[i].setCoord(pos.x, windowBounds.y);
        }
        else {
            objects[i].moveCoord();
        }
    }
}