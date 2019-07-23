#include "Object.hpp"

/** Constructor **/
Object::Object(float radius, sf::Vector2f _speed)
: position(0,0), speed(_speed), shape(radius)
{}

/** Getters and Setters **/
sf::Vector2f Object::getPosition() {
    return position;
}

void Object::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}
void Object::move() {
    position += speed;
}

sf::Drawable& Object::render(float interpolation) {
    shape.setPosition(position.x + speed.x*interpolation, position.y + speed.y*interpolation);
    return shape;
}