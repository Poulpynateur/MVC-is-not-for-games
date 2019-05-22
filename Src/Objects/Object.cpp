#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::CircleShape {
private:
    sf::Vector2f position;
    //Pixel to move each update
    sf::Vector2f movement;
public:
    Object(float radius, sf::Vector2f _movement);

    sf::Vector2f getLogicPosition();
    void updatePosition(float x, float y);
    void updateMove();

    Object& display(float interpolation);
};
/** Constructor **/
Object::Object(float radius, sf::Vector2f _movement) : sf::CircleShape(radius), position(0,0), movement(_movement) {
}

/** Getters and Setters **/
sf::Vector2f Object::getLogicPosition() {
    return position;
}

void Object::updatePosition(float x, float y) {
    position.x = x;
    position.y = y;
}
void Object::updateMove() {
    position += movement;
}

Object& Object::display(float interpolation) {
    this->setPosition(position.x + movement.x*interpolation, position.y + movement.y*interpolation);
    return *this;
}