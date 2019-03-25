#pragma once
#include <SFML/Graphics.hpp>
#include "Object.cpp"

class Dynamic : public Object
{
protected:
    //In pixel per milliseconds
    const sf::Vector2f gravity = sf::Vector2f(0, 0);
    float speed;

    //Unitary vector
    sf::Vector2f movement;
public:
    Dynamic(float radius, float speed);
    
    void move(sf::Int32 time_elapsed);
    sf::Vector2f getMovement() const;
    void setMovement(sf::Vector2f mov);
    Dynamic& setMoveX(float x);
    Dynamic& setMoveY(float y);
};

Dynamic::Dynamic(float radius, float _speed = 0.5) : Object(radius), speed(_speed)
{}

/*Movement*/
sf::Vector2f Dynamic::getMovement() const {
    return movement;}
void Dynamic::setMovement(sf::Vector2f mov) {
    movement = mov;}
Dynamic& Dynamic::setMoveX(float x) {
    this->movement.x = x;
    return *this;}
Dynamic& Dynamic::setMoveY(float y) {
    this->movement.y = y;
    return *this;}

void Dynamic::move(sf::Int32 time_elapsed) {
    movement.x *= speed * time_elapsed;
    movement.y *= speed * time_elapsed;

    std::cout << movement.x << " " << movement.y << '\n';
    sf::CircleShape::move(gravity + movement);
}