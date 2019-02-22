#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Static.cpp"
#include "Dynamic.cpp"
#include "Player.cpp"

class Elements : public sf::Drawable {
private:
    Player player;
    Static obstacle;

    virtual void draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const;
public:
    Elements(sf::Vector2u windowSize);
    Player& getPlayer();
};

Elements::Elements(sf::Vector2u windowSize) {
    player.setFillColor(sf::Color::Green);
    obstacle.setPosition(windowSize.x/2, windowSize.y/2);
}

//Temporary
void Elements::draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const {
    renderTarget.draw(player);
    renderTarget.draw(obstacle);
}

Player& Elements::getPlayer() {
    return player;
}