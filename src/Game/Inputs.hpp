#pragma once
#include <SFML/Graphics.hpp>

#include <bits/stdc++.h>
#include <vector>

struct Inputs {
private:
    //Key to listen
    std::vector<sf::Keyboard::Key> listening = {
        sf::Keyboard::Left,
        sf::Keyboard::Right
    };

    static std::unordered_map<sf::Keyboard::Key, bool> keys;

public:

    Inputs() {
        for(unsigned int i=0; i<listening.size(); i++) {
            keys[listening.at(i)] = false;
        }
    }

    void process() {
        //Refresh keys states
        for(unsigned int i=0; i<listening.size(); i++) {
            keys[listening.at(i)] = sf::Keyboard::isKeyPressed(listening.at(i));
        }
    }

    static std::unordered_map<sf::Keyboard::Key, bool> getKeys() {
        return keys;
    }
};