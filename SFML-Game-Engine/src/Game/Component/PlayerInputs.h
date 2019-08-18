#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <unordered_map>

class World;
class Player;

class PlayerInputs {

	sf::Int32 internal_clock = 0;
	const int fire_rate = 0;

public:
	void update(Player& player, World& world);
};