#pragma once
#include <SFML/Graphics.hpp>
#include "Dynamic.cpp"

class Player : public Dynamic {
private:
    //Number of frame between two shoots
    unsigned int fire_rate;
public:
    Player();
    bool canShoot(unsigned int frame_number);
};

Player::Player() : Dynamic(20) {
    fire_rate = 10;
    speed = 3;
    this->setFillColor(sf::Color::Green);
}

bool Player::canShoot(unsigned int frame_number) {
    return (frame_number % fire_rate == 0)? true : false;
}

