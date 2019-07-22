#pragma once

#include "../Object.hpp"

class Component {
private:
    /* data */
public:
    virtual void update(Object& object);
};
