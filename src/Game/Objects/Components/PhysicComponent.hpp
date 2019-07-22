#pragma once

#include "Component.hpp"
#include "../../Render.hpp"

class PhysicComponent : public Component {
public:
    void update(Object& object);
};