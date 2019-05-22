#pragma once
#include "Elements/Elements.cpp"
#include <cmath>

class GameLogic {
private:
    Elements& elements;
    sf::Int32 time_elapsed;
public:
    GameLogic(Elements& _elements);

    void keyEvents(sf::Int32 _time_elapsed);

    void movePlayer();
};

GameLogic::GameLogic(Elements& _elements) :
elements(_elements)
{}

void GameLogic::keyEvents(sf::Int32 _time_elapsed) {
    //For time dependant movements
    this->time_elapsed = (_time_elapsed==0)? 1 : _time_elapsed;   
    
    //Player
    elements.getPlayer().getMovement() = sf::Vector2f(0,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        elements.getPlayer().getMovement().x = -1*time_elapsed;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        elements.getPlayer().getMovement().x = 1*time_elapsed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        elements.getPlayer().getMovement().y = -1*time_elapsed;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        elements.getPlayer().getMovement().y = 1*time_elapsed;
}

void GameLogic::movePlayer() {
    for(unsigned int i=0; i<elements.getMap().size(); i++) {
        //getPlayer return Player& object
        elements.getPlayer().checkCollision(elements.getMap()[i]);
    }


    elements.getPlayer().move();
}