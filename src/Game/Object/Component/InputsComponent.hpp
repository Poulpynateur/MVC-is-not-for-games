#pragma once
#include <SFML/Graphics.hpp>

#include <bits/stdc++.h>

class Object;

class InputsComponent {
public:
    virtual void update(Object& object, std::unordered_map<sf::Keyboard::Key, bool>& keys);
};
