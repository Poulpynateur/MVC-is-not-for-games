#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Object.cpp"
#include "Dynamic.cpp"
#include "Player.cpp"

class Elements {
private:
    sf::Vector2u windowSize;
    Player player;
    std::vector<Object> map;
public:
    Elements(sf::Vector2u windowSize);

    void refresh(sf::RenderTarget &renderTarget);

    Player& getPlayer();
    std::vector<Object>& getMap();
};

Elements::Elements(sf::Vector2u windowSize) : windowSize(windowSize) {
    player.setPosition(windowSize.x/2, 0);

    srand (time(NULL));
    for(int i=0; i<1000; i++) {
        Object object(rand() % 40 + 10);
        object.setPosition(rand()%windowSize.x, rand()%windowSize.y);
        map.push_back(object);

    }
}

void Elements::refresh(sf::RenderTarget &renderTarget) {
    for(unsigned int i=0; i<map.size(); i++) {
        renderTarget.draw(map[i].refresh());
    }
    renderTarget.draw(player.refresh());
}

Player& Elements::getPlayer() {
    return player;}
std::vector<Object>& Elements::getMap() {
    return map;}