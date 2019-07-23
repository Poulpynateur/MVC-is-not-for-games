#include "PhysicComponent.hpp"

void PhysicComponent::update(Object& object,  sf::Vector2u& bounds) {

    sf::Vector2f pos = object.getPosition();

    if(pos.x > bounds.x) {
        object.setPosition(0, pos.y);
    }
    else if(pos.y > bounds.y) {
        object.setPosition(pos.x, 0);
    }
    else if(pos.x < 0) {
        object.setPosition(bounds.x, pos.y);
    }
    else if(pos.y < 0) {
        object.setPosition(pos.x, bounds.y);
    }
    else {
        object.move();
    }
}