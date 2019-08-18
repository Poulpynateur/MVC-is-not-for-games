#pragma once
#include <SFML/Graphics.hpp>

#include "../Engine/Object/Dynamic.h"

class Bullet : public Dynamic {
public:
	Bullet(sf::Vector2f _speed, sf::Vector2f _position, PhysicComponent* _physic);
};