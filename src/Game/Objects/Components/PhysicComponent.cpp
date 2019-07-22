#include "PhysicComponent.hpp"

void PhysicComponent::update(Object& object) {

    sf::Vector2f pos = object.getPosition();
    sf::Vector2u windowBounds = Render::resolution;

    if(pos.x > windowBounds.x) {
        object.setCoord(0, pos.y);
    }
    else if(pos.y > windowBounds.y) {
        object.setCoord(pos.x, 0);
    }
    else if(pos.x < 0) {
        object.setCoord(windowBounds.x, pos.y);
    }
    else if(pos.y < 0) {
        object.setCoord(pos.x, windowBounds.y);
    }
    else {
        object.moveCoord();
    }
}