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
    unsigned int game_state;
    InputsList list;
public:
    Inputs() {
        game_state = 1;
    };
    unsigned int getGameState();
    InputsList& get();

    void refresh();
};

unsigned int Inputs::getGameState() {
    return game_state;
}

//Return all pressed inputs
InputsList& Inputs::get() {
    return list;
}

//Refresh inputs
void Inputs::refresh() {
}