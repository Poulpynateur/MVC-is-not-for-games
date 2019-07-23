#pragma once
#include <SFML/Graphics.hpp>

#include <bits/stdc++.h>
#include <vector>

struct KeyListenner {
private:
    //Key to listen
    std::vector<sf::Keyboard::Key> listening = {
        sf::Keyboard::Left,
        sf::Keyboard::Right
    };

    std::unordered_map<sf::Keyboard::Key, bool> keys;

public:

    KeyListenner() {
        for(unsigned int i=0; i<listening.size(); i++) {
            keys[listening.at(i)] = false;
        }
    }

    void refresh() {
        //Refresh keys states
        for(unsigned int i=0; i<listening.size(); i++) {
            keys[listening.at(i)] = sf::Keyboard::isKeyPressed(listening.at(i));
        }
    }

    std::unordered_map<sf::Keyboard::Key, bool>& getKeys() {
        return keys;
    }
};