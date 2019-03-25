#pragma once
#include <SFML/Graphics.hpp>
#include "Dynamic.cpp"

class Player : public Dynamic {
private:
    //Delay between shoots (in ms)
    float fire_delay;

    void onCollision();
    void afterCollision();
public:
    Player();

    void refreshActionTimer(sf::Int32 time_elapsed);
    bool canShoot();
};

Player::Player() : Dynamic(20) {
    this->setFillColor(sf::Color::Green);

    action_timer = 0;
    fire_delay = 100;
}

void Player::refreshActionTimer(sf::Int32 time_elapsed) {
    movement.x = 0;
    movement.y = 0;
    action_timer += time_elapsed;}

bool Player::canShoot() {
    if(action_timer >= fire_delay) {
        action_timer = 0;
        return true;
    } else {
        return false;
    }
}

void Player::onCollision() {
    this->setFillColor(sf::Color::Magenta);
}
void Player::afterCollision() {
    this->setFillColor(sf::Color::Green);
}