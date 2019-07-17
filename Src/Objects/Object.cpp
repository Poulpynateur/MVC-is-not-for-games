#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::CircleShape {
private:
    sf::Vector2f coord;
    //Pixel to move each update
    sf::Vector2f movement;
public:
    Object(float radius, sf::Vector2f _movement);

    sf::Vector2f getCoord();
    void setCoord(float x, float y);
    void moveCoord();

    Object& display(float interpolation);
};
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

Object& Object::display(float interpolation) {
    this->setPosition(coord.x + movement.x*interpolation, coord.y + movement.y*interpolation);
    return *this;
}