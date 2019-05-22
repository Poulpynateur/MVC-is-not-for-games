#pragma once
#include <SFML/Graphics.hpp>
#include "Object.cpp"

class Dynamic : public Object
{
protected:
    //In pixel per frame
    float speed;
    sf::Vector2f movement;
public:
    Dynamic(float radius, sf::Vector2f _movement);

    //Move with a given vector
    void move(sf::Vector2f movement);
    void move();
};

Dynamic::Dynamic(float radius, sf::Vector2f _movement = sf::Vector2f())
: Object(radius), movement(_movement) {
}

void Dynamic::move(sf::Vector2f _movement) {
    sf::CircleShape::move(_movement * speed);
}
void Dynamic::move() {
    sf::CircleShape::move(movement);
}