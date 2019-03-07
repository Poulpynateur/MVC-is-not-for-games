#pragma once
#include <SFML/Graphics.hpp>
#include "Object.cpp"

class Dynamic : public Object
{
protected:
    //In pixel per milliseconds
    const sf::Vector2f gravity = sf::Vector2f(0, 0);
    float speed = 0.5;

    sf::Vector2f movement;
public:
    Dynamic(float radius);
    
    void move();
    sf::Vector2f& getMovement();
};

Dynamic::Dynamic(float radius) : Object(radius)
{}

/*Movement*/
sf::Vector2f& Dynamic::getMovement() {
    return this->movement;
}

void Dynamic::move() {
    movement.x *= speed;
    movement.y *= speed;
    sf::CircleShape::move(gravity + movement);
}