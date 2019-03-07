#pragma once
#include <SFML/Graphics.hpp>
#include "Dynamic.cpp"

class Player : public Dynamic {
protected:
    void onCollision();
    void afterCollision();
public:
    Player();
};

Player::Player() : Dynamic(20) {
    this->setFillColor(sf::Color::Green);
}

void Player::onCollision() {
    this->setFillColor(sf::Color::Green);
}
void Player::afterCollision() {
    this->setFillColor(sf::Color::Green);
}