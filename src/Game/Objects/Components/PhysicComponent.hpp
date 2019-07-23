#pragma once

#include "Component.hpp"

class PhysicComponent : public Component {
public:
    void update(Object& object, sf::Vector2u& bounds);
};