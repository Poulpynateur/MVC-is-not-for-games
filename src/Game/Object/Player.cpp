#include "Player.hpp"

Player::Player(PlayerInputs* _inputs)
: inputs(_inputs)
{}

Player::~Player() {
    delete inputs;
}

void Player::update(std::unordered_map<sf::Keyboard::Key, bool>& keys) {
    inputs->update(*this, keys);
}