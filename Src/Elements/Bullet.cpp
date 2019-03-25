#pragma once
#include <SFML/Graphics.hpp>
#include "Dynamic.cpp"

class Bullet : public Dynamic {
public:
    Bullet(sf::Vector2f direction, sf::Vector2f origin);
};

Bullet::Bullet(sf::Vector2f direction, sf::Vector2f origin) : Dynamic(5, 0.1) {
    this->setFillColor(sf::Color::Yellow);
    this->setMovement(direction);
    this->setPosition(origin);
}