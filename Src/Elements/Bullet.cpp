#pragma once
#include <SFML/Graphics.hpp>
#include "Dynamic.cpp"

#define BULLET_TTL 100
#define BULLET_SPEED 4.0F

class Bullet : public Dynamic {
private:
    unsigned int death_frame;
public:
    Bullet(sf::Vector2f _movement, sf::Vector2f pos, unsigned int frame_number);
    bool isDead(unsigned int frame_number);
};

Bullet::Bullet(sf::Vector2f _movement, sf::Vector2f pos, unsigned int frame_number) : Dynamic(5, _movement * BULLET_SPEED) {
    death_frame = frame_number + BULLET_TTL;
    this->setPosition(pos);
    this->setFillColor(sf::Color(155,255,0));
}

bool Bullet::isDead(unsigned int frame_number) {
    return (frame_number > death_frame)? true : false ;
}