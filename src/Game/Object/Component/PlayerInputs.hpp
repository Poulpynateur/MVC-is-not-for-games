#pragma once

#include <SFML/Graphics.hpp>

#include <bits/stdc++.h>

#include "InputsComponent.hpp"

class Player;

class PlayerInputs : InputsComponent {
public:
    void update(const Player& player, std::unordered_map<sf::Keyboard::Key, bool>& keys);
};