#pragma once
#include <SFML/Graphics.hpp>

#include "Component/InputsComponent.hpp"

class Object {
private:
    InputsComponent* inputs;
public:
    Object(InputsComponent* _inputs);
    ~Object();

    void update(std::unordered_map<sf::Keyboard::Key, bool>& keys);
};
