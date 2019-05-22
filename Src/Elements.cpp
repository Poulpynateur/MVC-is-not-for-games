#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Elements/Object.cpp"
#include "Elements/Dynamic.cpp"
#include "Elements/Player.cpp"
#include "Elements/Bullet.cpp"

#define STATIC_OBJECT_NBR 10

class Elements {
private:
    sf::Vector2u windowSize;
    Player player;
    std::vector<Object> map;
    std::vector<Bullet> projectiles;
public:
    Elements(sf::Vector2u windowSize);

    void refresh(sf::RenderTarget &renderTarget);

    Player& getPlayer();
    std::vector<Object>& getMap();
    std::vector<Bullet>& getProjectiles();
};

Elements::Elements(sf::Vector2u windowSize) : windowSize(windowSize) {
    player.setPosition(windowSize.x/2, 0);

    //Generate random shapes
    srand (time(NULL));
    for(int i=0; i<STATIC_OBJECT_NBR; i++) {
        Object object(rand() % 40 + 10);
        object.setPosition(rand()%windowSize.x, rand()%windowSize.y);
        map.push_back(object);
    }
}

void Elements::refresh(sf::RenderTarget &renderTarget) {
    for(unsigned int i(0); i<map.size(); i++) {
        renderTarget.draw(map[i]);
    }
    for(unsigned int i(0); i<projectiles.size(); i++) {
        renderTarget.draw(projectiles[i]);
    }
    renderTarget.draw(player);
}

Player& Elements::getPlayer() {
    return player;
}
std::vector<Object>& Elements::getMap() {
    return map;
}
std::vector<Bullet>& Elements::getProjectiles() {
    return projectiles;
}