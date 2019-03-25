#pragma once
#include "Elements/Elements.cpp"
#include <cmath>

class GameLogic {
private:
    Elements& elements;
    sf::Int32 time_elapsed;

    bool SPACE_BAR;
public:
    GameLogic(Elements& _elements);

    void keyEvents(sf::Int32 _time_elapsed);
    void movePlayer();
    void playerShoot();
};

GameLogic::GameLogic(Elements& _elements) :
elements(_elements) {
    SPACE_BAR = false;
}

void GameLogic::keyEvents(sf::Int32 _time_elapsed) {
    //For time dependant movements
    this->time_elapsed = (_time_elapsed==0)? 1 : _time_elapsed;
    
    //Probably better to handle key event less specifically (multiple action triggered by one event)
    SPACE_BAR = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        SPACE_BAR = true;
    
    //Player
    elements.getPlayer().refreshActionTimer(_time_elapsed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        elements.getPlayer().setMoveX(-1);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        elements.getPlayer().setMoveX(1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        elements.getPlayer().setMoveY(-1);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        elements.getPlayer().setMoveY(1);
}

void GameLogic::movePlayer() {
    for(unsigned int i=0; i<elements.getMap().size(); i++) {
        elements.getPlayer().checkCollision(elements.getMap()[i]);
    }
    elements.getPlayer().move(time_elapsed);
}

void GameLogic::playerShoot() {
    if(SPACE_BAR && elements.getPlayer().canShoot())
        elements.getProjectiles().push_back(Bullet(elements.getPlayer().getMovement(), elements.getPlayer().getPosition()));
    
    for(unsigned int i=0; i<elements.getProjectiles().size(); i++) {
        elements.getProjectiles()[i].move(time_elapsed);
    }
}