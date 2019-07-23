#pragma once
#include <SFML/Graphics.hpp>

#include "../World.hpp"

/**
 * More like dynamic than object but oh well
 */

class Object {
private:
    sf::Vector2f position;
    //Pixel to move each update
    sf::Vector2f speed;

    sf::CircleShape shape;

public:
    Object(float radius, sf::Vector2f _speed);

    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void move();

    //Refresh display to render
    sf::Drawable& render(float interpolation);

    //Refresh logic of the element (? Handle tume)
    virtual void update(World& world);
};