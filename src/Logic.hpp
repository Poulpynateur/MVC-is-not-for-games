#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Object.cpp"
#include "Inputs.cpp"

class Logic {
private:

    int game_state;
    InputsList inputsList;

    //In pixel
    sf::Vector2u windowBounds;
public:
    Logic(sf::Vector2u _windowBounds);

    int getGameState();
    void setInputList(InputsList& _inputsList);

    void update(std::vector<Object>& objects);
};