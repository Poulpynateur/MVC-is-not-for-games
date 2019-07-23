#pragma once

#include "Object.hpp"
#include "Component/PlayerInputs.hpp"

class Player {
private:
    PlayerInputs* inputs;
public:
    Player(PlayerInputs* _inputs);
    ~Player();

    void update(std::unordered_map<sf::Keyboard::Key, bool>& keys);
};