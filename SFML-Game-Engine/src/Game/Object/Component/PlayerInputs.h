#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <unordered_map>

class World;
class Player;

class PlayerInputs {
public:
	void update(Player& player);
};