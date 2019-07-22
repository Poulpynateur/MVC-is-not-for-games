#pragma once
#include <SFML/Graphics.hpp>

#include "Objects/Object.hpp"
#include "Inputs.hpp"

class Logic {
private:

    int game_state;

public:

    Logic() 
    : game_state(0)
    {}

    int getGameState() {
        return game_state;
    }

    void update(World& world) {
        for(unsigned int i(0); i<world.getObjects().size(); i++) {
            world.getObjects()[i].update(world);
        }
    }
};