#pragma once
#include "Interaction.cpp"

class Action : public Interaction {
private:
    sf::Int32 time_elapsed;
public:
    Action(Elements& _elements);
    void setEllapsedTime(sf::Int32 factor);

    void movePlayer(Elements& _elements);
};

Action::Action(Elements& _elements) :
Interaction(_elements)
{}
void Action::setEllapsedTime(sf::Int32 time_elapsed) {
    this->time_elapsed = (time_elapsed!=0)? time_elapsed : 1;
}

void Action::movePlayer(Elements& _elements) {
    sf::Vector2f next = elements.getPlayer().nextMovement(time_elapsed);
    //Only check if there is a collision
    resolvePlayerCollision(next);
    elements.getPlayer().move(next);
}