#pragma once

#include <iostream>

class World;
class Object;

class PlayerInputs {
public:
	void update(Object& object, std::unordered_map<sf::Keyboard::Key, bool>& keys);
};