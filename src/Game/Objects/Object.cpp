#include "Object.hpp"

/** Constructor **/
Object::Object(float radius, sf::Vector2f _movement)
: sf::CircleShape(radius), coord(0,0), movement(_movement) 
{}

/** Getters and Setters **/
sf::Vector2f Object::getCoord() {
    return coord;
}

void Object::setCoord(float x, float y) {
    coord.x = x;
    coord.y = y;
}
void Object::moveCoord() {
    coord += movement;
}

Object& Object::refresh(float interpolation) {
    this->setPosition(coord.x + movement.x*interpolation, coord.y + movement.y*interpolation);
    return *this;
}

void Object::update(World& world) {
    physic.update(*this);
}