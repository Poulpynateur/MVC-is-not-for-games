#include "Bullet.h"

Bullet::Bullet(sf::Vector2f _speed, sf::Vector2f _position, PhysicComponent* _physic)
: Dynamic(new sf::CircleShape(5), _physic)
{
	this->speed = _speed;
	this->position = _position;
	this->getShape()->setFillColor(sf::Color::Yellow);
}