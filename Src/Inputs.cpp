#pragma once
#include <SFML/Graphics.hpp>

struct InputsList {
    bool left = 0;
    bool rigth = 0;
    bool up = 0;
    bool down = 0;
};

class Inputs {
private:
    InputsList list;
public:
    InputsList& process();
};

//Return all pressed inputs
InputsList& Inputs::process() {
    return list;
}