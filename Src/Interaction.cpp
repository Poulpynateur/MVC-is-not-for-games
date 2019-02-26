#pragma once
#include "Elements/Elements.cpp"
#include <iostream>
#include <math.h>

class Interaction {
protected:
    Elements& elements;

    void resolvePlayerCollision(sf::Vector2f targetMovement);
public:
    Interaction(Elements& _elements);
};
Interaction::Interaction(Elements& _elements) :
elements(_elements)
{}

void Interaction::resolvePlayerCollision(sf::Vector2f targetMovement) {
    sf::Vector2f target = elements.getPlayer().getPosition() + targetMovement;
    sf::Vector2f obstacle = elements.getObstacle().getPosition(); 

    int target_radius = elements.getPlayer().getRadius();
    int obstacle_radius = elements.getObstacle().getRadius();

    int x = obstacle.x + obstacle_radius - (target.x + target_radius);
    int y = obstacle.y + obstacle_radius - (target.y + target_radius);
    int radius = target_radius+obstacle_radius;

    if(x*x + y*y <= radius*radius)
        elements.getObstacle().setFillColor(sf::Color::Red);
    else
        elements.getObstacle().setFillColor(sf::Color::White);
}