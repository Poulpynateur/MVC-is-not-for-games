#pragma once
#include <SFML/Graphics.hpp>

#include "Components/PhysicComponent.hpp"
#include "../World.hpp"

class Object : public sf::CircleShape {
private:

    sf::Vector2f coord;
    //Pixel to move each update
    sf::Vector2f movement;
    
    PhysicComponent physic;

public:
    Object(float radius, sf::Vector2f _movement);

    sf::Vector2f getCoord();
    void setCoord(float x, float y);
    void moveCoord();

    //Refresh display to render
    Object& refresh(float interpolation);

    //Refresh logic of the element (? Handle tume)
    void update(World& world);
};