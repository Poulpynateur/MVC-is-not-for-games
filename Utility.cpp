#pragma once
#include <SFML/Graphics.hpp>

namespace utility {
    //square
    template <class T>
    inline T sq(T value) {
        return value*value;
    }
    
    //No square root for opimization
    inline float pointsDistance(sf::Vector2f point1, sf::Vector2f point2) {
        return sq(point1.x - point2.x) + sq(point1.y - point2.y);
    }
};