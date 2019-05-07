#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::CircleShape {
public:
    Object(float radius);

    bool checkCollision(Object& object);
};

Object::Object(float radius) : sf::CircleShape(radius) {
    this->setOrigin(getPosition().x + getRadius(), getPosition().y + getRadius());
}

//Collision
bool Object::checkCollision(Object& object) {
    float distance = uti::ptDist(this->getPosition(), object.getPosition());
    float radius = uti::sq<float>(object.getRadius() + this->getRadius());

    return (distance <= radius)? true : false;
}