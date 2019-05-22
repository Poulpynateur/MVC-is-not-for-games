#pragma once
#include "Elements.cpp"
#include <cmath>

class GameLogic {
private:
    sf::Vector2f key_direction;
    unsigned int frame_number;
public:
    GameLogic() : frame_number(0) {};

    void initLoop();

    void keyEvents();
    void playerMove(Player& player);
    void playerShoot(Player& player, std::vector<Bullet>& projectiles);

    void projectilesMove(std::vector<Bullet>& projectiles, std::vector<Object>& map);
};

void GameLogic::initLoop() {
    key_direction = sf::Vector2f();
    frame_number ++;
}

void GameLogic::keyEvents() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        key_direction.x = -1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        key_direction.x = 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        key_direction.y = -1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        key_direction.y = 1;
}

void GameLogic::playerMove(Player& player) {
    player.move(key_direction);
}
void GameLogic::playerShoot(Player& player, std::vector<Bullet>& projectiles) {
    if((key_direction.x != 0 || key_direction.y != 0) && player.canShoot(frame_number)) {
        projectiles.push_back(Bullet(key_direction * -1.0f, player.getPosition(), frame_number));
    }
}

void GameLogic::projectilesMove(std::vector<Bullet>& projectiles, std::vector<Object>& map) {
    for(unsigned int i(0); i < projectiles.size(); i++) {
        if(projectiles[i].isDead(frame_number)) {
            projectiles.erase(projectiles.begin() + i);
        }
        else {
            projectiles[i].move();
            for(unsigned int j(0); j < map.size(); j++) {
                if(projectiles[i].checkCollision(map[j]))
                    projectiles.erase(projectiles.begin() + i);
            }
        }
    }
}